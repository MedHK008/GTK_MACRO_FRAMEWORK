#include "Combobox.h"

ComboBox *init_combobox(GtkWidget *pere, gchar *nom, gint x, gint y) {
    ComboBox *cb = (ComboBox*)malloc(sizeof(ComboBox));
    cb->comboBox = NULL;
    cb->container = pere;
    if (nom) {
        cb->nom = (gchar*)malloc(35 * sizeof(gchar));
        strcpy(cb->nom, nom);
    } else {
        cb->nom = NULL;
    }
    cb->posx = x;
    cb->posy = y;
    return cb;
}

void create_combobox(ComboBox *cb) {
    cb->comboBox = gtk_combo_box_text_new();
    gtk_widget_set_name(cb->comboBox, cb->nom);
    gtk_fixed_put(GTK_FIXED(cb->container), cb->comboBox, cb->posx, cb->posy);
}

void combobox_add(ComboBox *cb, gchar *text) {
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb->comboBox), NULL, text);
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb->comboBox), 0);
}

ComboBox* add_comboBox(GtkWidget *pere, gchar *nom, gint x, gint y) {
    ComboBox *combobox = init_combobox(pere, nom, x, y);
    create_combobox(combobox);
    return ((ComboBox*)combobox);
}

gchar *combobox_get(ComboBox *cb) {
    return gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(cb->comboBox));
}
