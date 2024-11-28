#ifndef BOUTTON_NORMAL_H_INCLUDED
#define BOUTTON_NORMAL_H_INCLUDED


#include <gtk/gtk.h>
#include <stdlib.h>
#include "Image.h"

typedef struct {
    GtkWidget* button;
    gchar* name;
    gchar* label;
    gchar* lien;
    guint width;
    guint height;
    gchar* bgColor;
    GtkWidget* image;
} SimpleButton;

SimpleButton* init_button_simple(gchar* nom, gchar* etiq, gchar* name, GtkWidget* img_widget, gint h, gint w, gchar* bgColor, gint x, gint y);
void add_bgcolor_btn(GtkWidget* widget, const gchar* color, gdouble opacity);
void creer_button_Simple(SimpleButton* B);
SimpleButton* add_button(gchar* name, gchar* label, gchar* path_to_image, gint height, gint width, gchar* bgColor, gint image_w, gint image_h);

#endif // BOUTTON_NORMAL_H_INCLUDED
