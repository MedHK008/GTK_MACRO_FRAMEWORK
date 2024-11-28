#include "SpinButton.h"


SpinButton* init_spin_button(gchar* name, gdouble val_min, gdouble val_max, gdouble pas, gdouble val_defaut,
                             gint height, gint width, gint wrap, gint digits, gint numeric, gint arrondis, gchar* color, gfloat color_opc) {
    SpinButton *Sb = NULL;
    Sb = (SpinButton*)malloc(sizeof(SpinButton));
    if (!Sb) {
        printf("\nErreur d'allocation!!!!!!\n");
        exit(0);
    }
    Sb->SpinButton = NULL;
    Sb->min = val_min;
    Sb->max = val_max;
    Sb->step = pas;
    Sb->name = name;
    Sb->value = val_defaut;
    Sb->height = height;
    Sb->width = width;
    Sb->wrap = wrap;
    Sb->digits = digits;
    Sb->numeric = numeric;
    Sb->arrondissement = arrondis;
    if (color) {
        Sb->bgcolor = (gchar*)malloc(30 * sizeof(gchar));
        if (Sb->bgcolor) {
            strcpy(Sb->bgcolor, color);
        } else {
            printf("\nErreur d'allocation\n");
        }
    }
    return Sb;
}

void add_bgcolor(GtkWidget* widget, const gchar* color, gdouble opacity) {
    GdkRGBA rgba;
    if (gdk_rgba_parse(&rgba, color)) {
        rgba.alpha = opacity;
        gtk_widget_override_background_color(widget, GTK_STATE_NORMAL, &rgba);
    } else {
        g_print("Erreur : Impossible de parser la couleur %s\n", color);
    }
}

void create_spin_button(SpinButton* Sb) {
    if ((Sb->max) >= (Sb->min)) {
        Sb->SpinButton = gtk_spin_button_new_with_range(Sb->min, Sb->max, Sb->step);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(Sb->SpinButton), Sb->value);
        if (Sb->name) gtk_widget_set_name(Sb->SpinButton, Sb->name);
        if ((Sb->height > 0) && (Sb->width > 0))
            gtk_widget_set_size_request(GTK_WIDGET(Sb->SpinButton), Sb->width, Sb->height);
        else
            printf("Height & Width should be positive\n");
        if (Sb->digits >= 0)
            gtk_spin_button_set_digits(GTK_SPIN_BUTTON(Sb->SpinButton), Sb->digits);
        else
            printf("\nDigits should be positive\n");
        if (Sb->wrap == 1)
            gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(Sb->SpinButton), TRUE);
        if (!(Sb->numeric))
            gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(Sb->SpinButton), FALSE);
        if (Sb->arrondissement == 1)
            gtk_spin_button_set_snap_to_ticks(GTK_SPIN_BUTTON(Sb->SpinButton), TRUE);
        if (Sb->bgcolor)
            add_bgcolor(GTK_WIDGET(Sb->SpinButton), Sb->bgcolor, 1.0);
    } else {
        printf("\nIntervalle du SpinButton n'est pas correct\n");
        exit(0);
    }
}

SpinButton* add_spin(gint x, gint y, gdouble val_min, gdouble val_max, gdouble pas, gdouble val_defaut,
                     gint height, gint width, gint wrap, gint digits, gint numeric, gint arrondis,
                     gchar* color, gfloat color_opc, gchar* name) {
    SpinButton *spin = init_spin_button(name, val_min, val_max, pas, val_defaut, height, width, wrap, digits, numeric, arrondis, color, color_opc);
    create_spin_button(spin);
    return spin;
}