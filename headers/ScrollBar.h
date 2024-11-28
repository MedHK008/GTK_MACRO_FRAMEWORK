#ifndef SCROLLBAR_H_INCLUDED
#define SCROLLBAR_H_INCLUDED

#include <gtk/gtk.h>

typedef struct {
    GtkWidget *widget;
    GtkWidget *parent;
    GtkWidget *fils;
    guint hpolic;
    guint vpolic;
    gint w;
    gint h;
} ScrollBar;

ScrollBar* initialiser_ScrollBar(gint w, gint h, guint hpl, guint vpl);

void creer_scrollbar(ScrollBar *scrbar, GtkWidget *pere, GtkWidget *conteneur);

void add_scrollbar(GtkWidget *grand_pere, GtkWidget *fixed, gint w, gint h, guint hpolic, guint vpolic);

#endif // SCROLLBAR_H_INCLUDED
