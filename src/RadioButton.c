
#include "RadioButton.h"

RadioButton* ajouter_radio_fin(RadioButton *L, gchar label[NBC], gchar *bgcolor, gboolean checked, gchar* name) {
    RadioButton *elem = (RadioButton*)malloc(sizeof(RadioButton));
    if (elem == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    elem->name = name;
    elem->suivant = NULL;
    strcpy(elem->label, label);
    elem->hexcolor = strdup(bgcolor);
    elem->checked = checked;
    if (!L) return elem;
    RadioButton *t = L;
    while (L->suivant) L = L->suivant;
    L->suivant = elem;
    return t;
}

radio* grouper_radio(RadioButton *L, GtkWidget *parent) {
    radio *radioButtons = (radio*)malloc(sizeof(radio));
    if (radioButtons == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    radioButtons->fixed = gtk_fixed_new();
    radioButtons->liste = L;
    radioButtons->parent = parent;
    return radioButtons;
}

void create_radio(radio *R, gint x, gint y) {
    GtkWidget *first_radio = NULL;
    while (R->liste) {
        R->liste->pRadio = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(first_radio), R->liste->label);
        if (R->liste->name) gtk_widget_set_name(R->liste->pRadio, R->liste->name);
        if (R->liste->hexcolor) {
            GdkRGBA color;
            gdk_rgba_parse(&color, R->liste->hexcolor);
            gtk_widget_override_background_color(R->liste->pRadio, GTK_STATE_FLAG_NORMAL, &color);
        }
        if (R->liste->checked) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(R->liste->pRadio), TRUE);
        }
        if (!first_radio) first_radio = R->liste->pRadio;
        gtk_fixed_put(GTK_FIXED(R->fixed), R->liste->pRadio, x, y);
        y += 25;
        R->liste = R->liste->suivant;
    }
}

GtkWidget* add_radio(int numButtons, gint x, gint y, char *labels[], char *colors[], gboolean checked[], gchar* name[], gboolean orientation) {
    RadioButton *liste_radio = NULL;
    GtkWidget *box = NULL;
    for (int i = 0; i < numButtons; i++) {
        liste_radio = ajouter_radio_fin(liste_radio, labels[i], colors[i], checked[i], name[i]);
    }
    radio *grouped_radio = grouper_radio(liste_radio, NULL);
    if (orientation) box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    else box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *first_radio = NULL;
    while (grouped_radio->liste) {
        grouped_radio->liste->pRadio = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(first_radio), grouped_radio->liste->label);
        if (grouped_radio->liste->hexcolor) {
            GdkRGBA color;
            gdk_rgba_parse(&color, grouped_radio->liste->hexcolor);
            gtk_widget_override_background_color(grouped_radio->liste->pRadio, GTK_STATE_FLAG_NORMAL, &color);
        }
        if (grouped_radio->liste->checked) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(grouped_radio->liste->pRadio), TRUE);
        }
        if (!first_radio) first_radio = grouped_radio->liste->pRadio;
        gtk_box_pack_start(GTK_BOX(box), grouped_radio->liste->pRadio, FALSE, FALSE, 0);
        grouped_radio->liste = grouped_radio->liste->suivant;
    }
    return box;
}