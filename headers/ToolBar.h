#ifndef TOOL_BAR_H_INCLUDED
#define TOOL_BAR_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct {
    GtkWidget *widget;
    gint h;
    gint w;
    const gchar *icon;
    gchar *text;
    GtkWidget *parent;
    gint pos;
} item_bar;

typedef struct {
    GtkWidget *widget;
    GtkWidget *parent;
    gchar orientation;
    gint h;
    gint w;
} toolbar;

toolbar *initialiser_toolbar(GtkWidget *pere, gchar orientation, gint w, gint h, GtkToolbarStyle stl, GtkIconSize siz);

toolbar *creer_toolbar(toolbar *tbar);

item_bar *initialiser_item_stock(GtkWidget *pere, const gchar *icon, gchar *lab, gint w, gint h, gint pos);

void creer_toolitem(item_bar *toolitem, toolbar *bar, gboolean choix, void (*fonction)(GtkWidget*, gpointer), gchar *type, gpointer data);

GtkWidget *creer_separ(GtkWidget *sep, GtkWidget *pere, gint pos);

toolbar *add_toolbar(GtkWidget *box, gchar orientation, gint x, gint y, gint w, gint h, GtkToolbarStyle sty, GtkIconSize size_icone, gint padding);

void add_item_bar(toolbar *bar_pere, const gchar *icon, gchar *label, gint w, gint h, gint pos);

#endif // TOOL_BAR_H_INCLUDED
