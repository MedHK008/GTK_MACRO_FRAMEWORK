#ifndef COMBOBOX_H_INCLUDED
#define COMBOBOX_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
// Structure de la combobox
typedef struct {
    GtkWidget *comboBox;
    GtkWidget *container;
    gchar *nom;
    gint posx;
    gint posy;
} ComboBox;

// Fonction d'initialisation de la combobox
ComboBox *init_combobox(GtkWidget *pere, gchar *nom, gint x, gint y);

// Fonction de création de la combobox
void create_combobox(ComboBox *cb);

// Fonction d'ajout d'un élément à la combobox
void combobox_add(ComboBox *cb, gchar *text);

ComboBox* add_comboBox(GtkWidget *pere, gchar *nom, gint x, gint y);

// Fonction de récupération du texte de l'élément sélectionné dans la combobox
gchar *combobox_get(ComboBox *cb);

#endif // COMBOBOX_H_INCLUDED
