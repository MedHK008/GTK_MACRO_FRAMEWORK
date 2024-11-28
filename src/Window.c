#include "Window.h"

Fenetre* initialiser_win(gchar* titre, gchar* icon_path, gchar *name, gchar* bgcolor, guint h, guint w, GtkWindowPosition pos,
                          gint x, gint y, guint border, gboolean resizable)
{
    Fenetre* win = (Fenetre*) malloc(sizeof(Fenetre));
    if (!win) {
        printf("\nErreur d'allocation de mémoire.");
        exit(-1);
    }

    win->window = NULL;

    if (titre)
        win->titre = g_strdup(titre);
    else
        win->titre = NULL;

    if (icon_path)
        win->icon = g_strdup(icon_path);
    else
        win->icon = NULL;

    if (name)
        win->name = g_strdup(name);
    else
        win->name = NULL;

    if (bgcolor)
        win->bgcolor = g_strdup(bgcolor);
    else
        win->bgcolor = NULL;

    win->hauteur = h;
    win->largeur = w;
    win->position_init = pos;
    win->posx = x;
    win->posy = y;
    win->border_width = border;
    win->modifiable = resizable;

    return win;
}

void create_window(Fenetre *W)
{
    W->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    if (W->titre)
        gtk_window_set_title(GTK_WINDOW(W->window), W->titre);

    if (W->name)
        gtk_widget_set_name(W->window, W->name);

    if (W->icon)
        gtk_window_set_icon_from_file(GTK_WINDOW(W->window), W->icon, NULL);

    if (W->bgcolor) {
        GdkRGBA color;
        if (gdk_rgba_parse(&color, W->bgcolor)) {
            gtk_widget_override_background_color(W->window, GTK_STATE_NORMAL, &color);
        } else {
            g_warning("\nImpossible de définir la couleur de fond.");
        }
    }

    if (W->hauteur > 0 && W->largeur > 0)
        gtk_window_set_default_size(GTK_WINDOW(W->window), W->largeur, W->hauteur);

    if (!W->position_init)
        gtk_window_move(GTK_WINDOW(W->window), W->posx, W->posy);
    else
        gtk_window_set_position(GTK_WINDOW(W->window), W->position_init);

    gtk_container_set_border_width(GTK_CONTAINER(W->window), W->border_width);
    gtk_window_set_resizable(GTK_WINDOW(W->window), W->modifiable);
}

Fenetre* add_window(gchar* title, gchar* icon_path, gchar* name, gchar* bgcolor,
                   guint width, guint height, GtkWindowPosition pos_init,
                   guint posx, guint posy, guint border_size, gboolean resizable)
{
    Fenetre* ma_fenetre = initialiser_win(title, icon_path, name, bgcolor, width, height, pos_init, posx, posy, border_size, resizable);
    create_window(ma_fenetre);
    return ma_fenetre;
}