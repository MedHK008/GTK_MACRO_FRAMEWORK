#include "SimpleButton.h"

SimpleButton* init_button_simple(gchar* nom, gchar* etiq, gchar* name, GtkWidget* img_widget, gint h, gint w, gchar* bgColor, gint x, gint y) {
    SimpleButton* b = (SimpleButton*)malloc(sizeof(SimpleButton));
    if (!b) {
        printf("\nErreur d'allocation !!\n");
        exit(0);
    }

    b->name = NULL;
    b->label = NULL;
    b->image = NULL;
    b->bgColor = NULL;
    if (etiq) {
        b->label = (gchar*)malloc(30 * sizeof(gchar));
        strcpy(b->label, etiq);
    }
    if (name) {
        b->name = (gchar*)malloc(30 * sizeof(gchar));
        strcpy(b->name, name);
    }
    if (bgColor) {
        b->bgColor = (gchar*)malloc(30 * sizeof(gchar));
        strcpy(b->bgColor, bgColor);
    }
    b->width = w;
    b->height = h;
    b->image = img_widget;
    return b;
}

void add_bgcolor_btn(GtkWidget* widget, const gchar* color, gdouble opacity) {
    GdkRGBA rgba;

    if (gdk_rgba_parse(&rgba, color)) {
        rgba.alpha = opacity;
        gtk_widget_override_background_color(widget, GTK_STATE_NORMAL, &rgba);
    } else {
        g_print("Erreur : Impossible de parser la couleur %s\n", color);
    }
}

void creer_button_Simple(SimpleButton* B) {
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    if (B->bgColor)
        add_bgcolor_btn(vbox, B->bgColor, 1.0);

    GtkWidget* label = NULL;
    if (B->label) {
        label = gtk_label_new(B->label);
        gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
        gtk_widget_set_valign(label, GTK_ALIGN_CENTER);
        gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    }

    if (B->image)
        gtk_box_pack_start(GTK_BOX(vbox), B->image, TRUE, TRUE, 0);

    B->button = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(B->button), vbox);

    if (B->name)
        gtk_widget_set_name(B->button, B->name);

    if ((B->width > 0) && (B->height > 0))
        gtk_widget_set_size_request(B->button, B->width, B->height);
}

SimpleButton* add_button(gchar* name, gchar* label, gchar* path_to_image, gint height, gint width, gchar* bgColor, gint image_w, gint image_h) {
    SimpleButton* simpleButton = NULL;

    image* img = initialiser_image(simpleButton, 1, path_to_image, GTK_ICON_SIZE_BUTTON, image_w, image_h);
    creer_img(img);
    simpleButton = init_button_simple("mon_bouton", label, name, img->widget, height, width, bgColor, 0, 0);
    creer_button_Simple(simpleButton);
    return simpleButton;
}
