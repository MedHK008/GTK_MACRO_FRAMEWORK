#ifndef COCHER_H_INCLUDED
#define COCHER_H_INCLUDED

#include <gtk/gtk.h>
#include <glib.h>

typedef struct coche {
    GtkWidget *parent;  
    gchar *label;       
    gchar *name;
    GtkWidget *boutcoche;
    gint x;
    gint y;
    gchar *gui;         
    struct coche *next; 
} cocher;

typedef struct {
    cocher *head; 
} CheckboxList;

CheckboxList *init_checkbox_list();
cocher *init_cocher(GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name);
GtkWidget *add_cocher(CheckboxList *list, GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name);

#endif // COCHER_H_INCLUDED
