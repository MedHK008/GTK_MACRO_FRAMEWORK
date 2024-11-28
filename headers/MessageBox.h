#ifndef MessageBox_H_INCLUDED
#define MessageBox_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    GtkWidget *message_box;
    GtkWidget *parent;
    GtkWidget *fixed;
    gchar *titre;
    gchar *icon;
    gchar *color;
    gint modal;
    gint h;
    gint w;
} MessageBox;

MessageBox *initialiser_MessageBox();
MessageBox *set_attribue(MessageBox *BM, GtkWidget *parent, gchar *titre, gint modal, gchar *color, gchar *icon, gint w, gint h);
void definir_attribut_MessageBox(MessageBox *BM);
MessageBox *Add_MessageBox(GtkWidget *parent, gchar *titre, gint modal, gchar *color, gchar *icon, gint w, gint h);
void ajouter_to_MessageBox(MessageBox *BM, GtkWidget *widget, gint x, gint y);
void declencher_MessageBox(MessageBox *BM, GtkWidget *button);

#endif // MessageBox_H_INCLUDED
