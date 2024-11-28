#include "CheckBox.h"

CheckboxList *init_checkbox_list() {
    CheckboxList *list = (CheckboxList *)malloc(sizeof(CheckboxList));
    if (list == NULL) return NULL;
    list->head = NULL;
    return list;
}

cocher *create_cocher(GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    cocher *C = (cocher *)malloc(sizeof(cocher));
    if (C == NULL) return NULL;
    init_cocher_elements(C);
    if(name) C->name = name;
    if(parent) C->parent = parent;
    if(label) C->label = g_strdup(label);
    if(x) C->x = x;
    if(y) C->y = y;
    C->boutcoche = gtk_check_button_new_with_label(C->label);
    C->next = NULL;

    if (gui) {
        C->gui = g_strdup(gui);
        GdkColor color;
        gdk_color_parse(C->gui, &color);
        gtk_widget_modify_bg(C->boutcoche, GTK_STATE_NORMAL, &color);
    }
    if (C->name)
        gtk_widget_set_name(C->boutcoche, C->name);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(C->boutcoche), checked);

    return C;
}

void init_cocher_elements(cocher *C) {
    C->name = NULL;
    C->parent = NULL;
    C->label = NULL;
    C->boutcoche = NULL;
    C->x = 0;
    C->y = 0;
    C->gui = NULL;
    C->next = NULL;
}

GtkWidget *add_cocher(CheckboxList *list, GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    cocher *checkbox = init_cocher(parent, label, x, y, gui, checked, name);
    if (checkbox == NULL) return NULL;

    checkbox->next = list->head;
    list->head = checkbox;

    return checkbox->boutcoche;
}
