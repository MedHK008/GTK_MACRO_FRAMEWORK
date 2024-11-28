#include "Menu.h"

MenuBar *add_MenuBar(GtkPackDirection orientation, GtkWidget *parent)
{
    MenuBar *mbar = (MenuBar*) malloc(sizeof(MenuBar));
    if (!mbar) {
        printf("\nEchec d'allocation mémoire pour la barre de Menu");
        exit(-1);
    }
    mbar->parent = parent;
    mbar->liste = NULL;
    mbar->MenuBar = gtk_menu_bar_new();
    if (orientation)
        gtk_menu_bar_set_pack_direction(GTK_MENU_BAR(mbar->MenuBar), orientation);
    return mbar;
}

Menu* init_menu_item(guint type, gchar *nom, gboolean Submenu, gboolean isRadioGroup)
{
    Menu *NM = malloc(sizeof(Menu));
    if (!NM) {
        g_critical("Echec d'allocation mémoire pour l'élément de Menu");
        exit(-1);
    }
    if (nom) {
        NM->nom = g_strdup(nom);
    } else {
        NM->nom = NULL;
    }
    NM->IsSubmenu = Submenu;
    NM->IsradioGroup = isRadioGroup;
    NM->type_composant = type;
    NM->liste = NULL;
    NM->suivant = NULL;
    return NM;
}

void ajouter_menu(MenuBar *M, Menu *menu_child)
{
    if (!M->liste)
        M->liste = menu_child;
    else {
        Menu *courant;
        for (courant = M->liste; courant->suivant; courant = courant->suivant);
        courant->suivant = menu_child;
        menu_child->suivant = NULL;
    }
    menu_child->menu_item = gtk_menu_item_new_with_label(menu_child->nom);
    menu_child->MENU = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_child->menu_item), menu_child->MENU);
    gtk_menu_shell_append(GTK_MENU_SHELL(M->MenuBar), menu_child->menu_item);
}

Menu* RadioGroup(Menu* M)
{
    Menu *courant;
    for (courant = M; courant; courant = courant->suivant)
        if (courant->IsradioGroup)
            return courant;
    return NULL;
}

void ajouter_menu_item(Menu *parent_menu, Menu *menu_elem, const gchar *icon)
{
    if (!parent_menu->liste)
        parent_menu->liste = menu_elem;
    else {
        Menu *courant;
        for (courant = parent_menu->liste; courant->suivant; courant = courant->suivant) {}
        courant->suivant = menu_elem;
        menu_elem->suivant = NULL;
    }
    if (!menu_elem->IsSubmenu) {
        switch (menu_elem->type_composant) {
            case 1:
                menu_elem->menu_item = gtk_check_menu_item_new_with_mnemonic(menu_elem->nom);
                break;
            case 2:
                menu_elem->menu_item = gtk_separator_menu_item_new();
                break;
            case 3:
                if (icon) {
                    menu_elem->menu_item = gtk_menu_item_new_with_mnemonic(menu_elem->nom);
                    GtkWidget *image = gtk_image_new_from_file(icon);
                    gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(menu_elem->menu_item), image);
                } else {
                    menu_elem->menu_item = gtk_menu_item_new_with_mnemonic(menu_elem->nom);
                }
                break;
            case 4:
                Menu* Rgroup = RadioGroup(parent_menu->liste);
                if ((!parent_menu->liste) || (!Rgroup))
                    menu_elem->menu_item = gtk_radio_menu_item_new_with_mnemonic(NULL, menu_elem->nom);
                else if (Rgroup)
                    menu_elem->menu_item = gtk_radio_menu_item_new_with_mnemonic_from_widget(GTK_RADIO_MENU_ITEM(Rgroup->menu_item), menu_elem->nom);
                break;
            default:
                menu_elem->menu_item = gtk_menu_item_new_with_mnemonic(menu_elem->nom);
                break;
        }
    } else {
        menu_elem->menu_item = gtk_menu_item_new_with_mnemonic(menu_elem->nom);
        menu_elem->MENU = gtk_menu_new();
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_elem->menu_item), menu_elem->MENU);
    }
    gtk_menu_shell_append(GTK_MENU_SHELL(parent_menu->MENU), menu_elem->menu_item);
}

Menu *add_menu(MenuBar *mbar, gchar *name)
{
    Menu *new_menu_item = init_menu_item(0, name, TRUE, FALSE);
    ajouter_menu(mbar, new_menu_item);
    return new_menu_item;
}

Menu *add_menu_item(Menu *parent_menu, guint type, gchar *name, gboolean isSubmenu, gboolean isRadioGroup, gchar *icon)
{
    Menu *new_menu_item = init_menu_item(type, name, isSubmenu, isRadioGroup);
    ajouter_menu_item(parent_menu, new_menu_item, icon);
    return new_menu_item;
}