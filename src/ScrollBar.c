
#include "ScrollBar.h"

ScrollBar* initialiser_ScrollBar(gint w, gint h, guint hpl, guint vpl) {
    ScrollBar *scrBar = (ScrollBar *)g_malloc(sizeof(ScrollBar));
    scrBar->widget = gtk_scrolled_window_new(NULL, NULL);
    scrBar->h = h;
    scrBar->w = w;
    scrBar->hpolic = hpl;
    scrBar->vpolic = vpl;
    return scrBar;
}

void creer_scrollbar(ScrollBar *scrbar, GtkWidget *pere, GtkWidget *conteneur) {
    gtk_container_add(GTK_CONTAINER(pere), scrbar->widget);
    gtk_widget_set_size_request(scrbar->widget, scrbar->w, scrbar->h);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrbar->widget), conteneur);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrbar->widget), scrbar->vpolic, scrbar->hpolic);
}

void add_scrollbar(GtkWidget *grand_pere, GtkWidget *fixed, gint w, gint h, guint hpolic, guint vpolic) {
    ScrollBar *scrolled = initialiser_ScrollBar(w, h, hpolic, vpolic);
    creer_scrollbar(scrolled, grand_pere, fixed);
}