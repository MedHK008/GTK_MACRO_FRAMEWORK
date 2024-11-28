#ifndef SPIN_BUTTON_H_INCLUDED
#define SPIN_BUTTON_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    GtkWidget *SpinButton;
    gchar* name;
    gdouble min;
    gdouble max;
    gdouble step;
    gdouble value;
    gint height;
    gint width;
    gint wrap;
    gint digits;
    gint numeric;
    gint arrondissement;
    gchar* bgcolor;
} SpinButton;

SpinButton* init_spin_button(gchar* name, gdouble val_min, gdouble val_max, gdouble pas, gdouble val_defaut,
                             gint height, gint width, gint wrap, gint digits, gint numeric, gint arrondis, gchar* color, gfloat color_opc);

void add_bgcolor(GtkWidget* widget, const gchar* color, gdouble opacity);

void create_spin_button(SpinButton* Sb);

SpinButton* add_spin(gint x, gint y, gdouble val_min, gdouble val_max, gdouble pas, gdouble val_defaut,
                     gint height, gint width, gint wrap, gint digits, gint numeric, gint arrondis,
                     gchar* color, gfloat color_opc, gchar* name);

#endif // SPIN_BUTTON_H_INCLUDED
