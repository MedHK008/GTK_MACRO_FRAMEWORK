#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
  GtkWidget *window;
  gchar *titre;
  gchar *icon;
  gchar *name;
  gchar *bgcolor;
  guint hauteur;
  guint largeur;
  gint posx;
  gint posy;
  GtkWindowPosition position_init;
  guint border_width;
  gboolean modifiable;
} Fenetre;

Fenetre* initialiser_win(gchar* titre, gchar* icon_path, gchar *name, gchar* bgcolor, guint h, guint w, GtkWindowPosition pos,
                          gint x, gint y, guint border, gboolean resizable);

void create_window(Fenetre *W);

Fenetre* add_window(gchar* title, gchar* icon_path, gchar* name, gchar* bgcolor,
                   guint width, guint height, GtkWindowPosition pos_init,
                   guint posx, guint posy, guint border_size, gboolean resizable);

#endif // WINDOW_H_INCLUDED
