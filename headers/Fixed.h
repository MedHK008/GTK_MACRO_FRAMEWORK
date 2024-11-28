#ifndef FIXED_H_INCLUDED
#define FIXED_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct {
    GtkWidget* fixed;  // Pointer to the GtkFixed container
} Fixed;

// Function to initialize a GtkFixed container
Fixed* init_gtk_fixed();

// Function to add a widget to a GtkFixed container
void add_widget_to_fixed(Fixed* fixedInfo, GtkWidget* widget, gint x, gint y);

// Function to remove a widget from a GtkFixed container
void remove_widget_from_fixed(Fixed* fixedInfo, GtkWidget* widget);

// Function to free memory allocated for Fixed
void free_gtk_fixed_info(Fixed* fixedInfo);

#endif // FIXED_H_INCLUDED
