#ifndef Tab_H_INCLUDED
#define Tab_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tab {
  GtkWidget *Tab;
  char *titre;
  GtkWidget *contenu;
  gboolean actif;
} Tab;

Tab *Tab_nouveau(const char *titre, GtkWidget *contenu);
GtkWidget *Tab_get_widget(Tab *Tab);
const char *Tab_get_titre(Tab *Tab);
void Tab_set_titre(Tab *Tab, const char *titre);
void Tab_set_contenu(Tab *Tab, GtkWidget *contenu);
void Tab_activer(Tab *Tab);
void add_Tab(GtkWidget* notebook, GtkWidget* fixed, gchar* label, const char* bgcolor);
void add_to_window(GtkWidget* notebook, GtkWidget* window);

#endif // Tab_H_INCLUDED
