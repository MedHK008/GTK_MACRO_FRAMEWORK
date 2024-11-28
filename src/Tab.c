
#include "Tab.h"

Tab *Tab_nouveau(const char *titre, GtkWidget *contenu) {
  Tab *Tab = malloc(sizeof(Tab));
  Tab->titre = strdup(titre);
  Tab->Tab = gtk_notebook_new();
  gtk_container_add(GTK_CONTAINER(Tab->Tab), contenu);
  Tab->actif = FALSE;
  return Tab;
}

GtkWidget *Tab_get_widget(Tab *Tab) {
  return Tab->Tab;
}

const char *Tab_get_titre(Tab *Tab) {
  return Tab->titre;
}

void Tab_set_titre(Tab *Tab, const char *titre) {
  free(Tab->titre);
  Tab->titre = strdup(titre);
  gtk_notebook_set_tab_label_text(GTK_NOTEBOOK(Tab->Tab), Tab->Tab, titre);
}

void Tab_set_contenu(Tab *Tab, GtkWidget *contenu) {
  if (Tab->contenu != NULL)
    gtk_container_remove(GTK_CONTAINER(Tab->Tab), Tab->contenu);
  Tab->contenu = contenu;
  gtk_container_add(GTK_CONTAINER(Tab->Tab), contenu);
}

void Tab_activer(Tab *Tab) {
  Tab->actif = TRUE;
  gtk_notebook_set_current_page(GTK_NOTEBOOK(Tab->Tab), 0);
}

void add_Tab(GtkWidget* notebook, GtkWidget* fixed, gchar* label, const char* bgcolor) {
    GtkWidget* tab_label = gtk_label_new(label);
    GdkRGBA color;
    gdk_rgba_parse(&color, bgcolor);
    gtk_widget_override_background_color(tab_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), fixed, tab_label);
}

void add_to_window(GtkWidget* notebook, GtkWidget* window) {
    gtk_container_add(GTK_CONTAINER(window), notebook);
}