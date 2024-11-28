#include "ToolBar.h"

toolbar *initialiser_toolbar(GtkWidget *pere, gchar orientation, gint w, gint h, GtkToolbarStyle stl, GtkIconSize siz)
{
    toolbar *tbar = (toolbar *)g_malloc(sizeof(toolbar));
    tbar->widget = gtk_toolbar_new();
    tbar->parent = pere;
    tbar->orientation = orientation;
    tbar->w = w;
    tbar->h = h;
    if (stl)
        gtk_toolbar_set_style(GTK_TOOLBAR(tbar->widget), stl);
    if (siz)
        gtk_toolbar_set_icon_size(GTK_TOOLBAR(tbar->widget), siz);
    return tbar;
}

toolbar *creer_toolbar(toolbar *tbar)
{
    if (tbar->orientation == 'h' || tbar->orientation == 'H')
        gtk_orientable_set_orientation(GTK_TOOLBAR(tbar->widget), GTK_ORIENTATION_HORIZONTAL);
    else
        gtk_orientable_set_orientation(GTK_TOOLBAR(tbar->widget), GTK_ORIENTATION_VERTICAL);
    return tbar;
}

item_bar *initialiser_item_stock(GtkWidget *pere, const gchar *icon, gchar *lab, gint w, gint h, gint pos)
{
    item_bar *item = (item_bar *)g_malloc(sizeof(item_bar));
    item->widget = gtk_tool_item_new();
    item->text = lab;
    item->icon = icon;
    item->pos = pos;
    item->w = w;
    item->h = h;
    return item;
}

void creer_toolitem(item_bar *toolitem, toolbar *bar, gboolean choix, void (*fonction)(GtkWidget*, gpointer), gchar *type, gpointer data)
{
    GtkWidget *box = gtk_vbox_new(FALSE, 5);
    GtkWidget *button = gtk_tool_button_new_from_stock(toolitem->icon);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    GtkWidget *label = gtk_label_new(toolitem->text);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(toolitem->widget), box);
    gtk_toolbar_insert(GTK_TOOLBAR(bar->widget), toolitem->widget, toolitem->pos);
    if (toolitem->w && toolitem->h)
        gtk_widget_set_size_request(toolitem->widget, toolitem->w, toolitem->h);
    if (choix)
        g_signal_connect(G_OBJECT(button), type, G_CALLBACK(fonction), data);
}

GtkWidget *creer_separ(GtkWidget *sep, GtkWidget *pere, gint pos)
{
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(pere), sep, pos);
    return sep;
}

toolbar *add_toolbar(GtkWidget *box, gchar orientation, gint x, gint y, gint w, gint h, GtkToolbarStyle sty, GtkIconSize size_icone, gint padding)
{
    toolbar *tool_bar = initialiser_toolbar(box, orientation, w, h, sty, size_icone);
    creer_toolbar(tool_bar);
    gtk_box_pack_start(GTK_BOX(box), tool_bar->widget, FALSE, FALSE, padding);
    return tool_bar;
}

void add_item_bar(toolbar *bar_pere, const gchar *icon, gchar *label, gint w, gint h, gint pos)
{
    item_bar *element = initialiser_item_stock(bar_pere->widget, icon, label, w, h, pos);
    creer_toolitem(element, bar_pere, 0, NULL, NULL, NULL);
}