#ifndef RADIO_H_INCLUDED
#define RADIO_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NBC 200  // Maximum number of characters for label

typedef struct RadioButton {
    GtkWidget *pRadio;
    gchar* name;
    gchar label[NBC];
    gchar *hexcolor;
    gboolean checked;
    struct RadioButton *suivant;
} RadioButton;

typedef struct radio {
    GtkWidget *fixed;
    GtkWidget *parent;
    GtkWidget *pRadio;
    RadioButton *liste;
} radio;

RadioButton* ajouter_radio_fin(RadioButton *L, gchar label[NBC], gchar *bgcolor, gboolean checked, gchar* name);

radio* grouper_radio(RadioButton *L, GtkWidget *parent);

void create_radio(radio *R, gint x, gint y);

GtkWidget* add_radio(int numButtons, gint x, gint y, char *labels[], char *colors[], gboolean checked[], gchar* name[], gboolean orientation);

#endif // RADIO_H_INCLUDED
