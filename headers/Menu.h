#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

guint DEFAULT_MENU = 0;
guint CHECKBOX_MENU = 1;
guint SEPARATOR_MENU = 2;
guint IMAGE_MENU = 3;
guint RADIO_MENU = 4;

typedef struct Menu {
    GtkWidget *MENU;
    GtkWidget *menu_item;
    guint type_composant;
    gboolean IsradioGroup;
    gboolean IsSubmenu;
    gchar *nom;
    struct Menu *suivant;
    struct Menu *liste;
} Menu;

typedef struct {
    GtkWidget *MenuBar;
    GtkWidget *parent;
    GtkPackDirection orientation;
    Menu *liste;
} MenuBar;

MenuBar *add_MenuBar(GtkPackDirection orientation, GtkWidget *parent);
Menu* init_menu_item(guint type, gchar *nom, gboolean Submenu, gboolean isRadioGroup);
void ajouter_menu(MenuBar *M, Menu *menu_child);
Menu* RadioGroup(Menu* M);
void ajouter_menu_item(Menu *parent_menu, Menu *menu_elem, const gchar *icon);
Menu *add_menu(MenuBar *mbar, gchar *name);
Menu *add_menu_item(Menu *parent_menu, guint type, gchar *name, gboolean isSubmenu, gboolean isRadioGroup, gchar *icon);

#endif // MENU_H_INCLUDED
