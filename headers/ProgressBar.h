#ifndef PROG_BAR_H_INCLUDED
#define PROG_BAR_H_INCLUDED

#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *widget;
    GtkWidget *parent;
    gdouble fraction;
    gdouble unite;
    gint h;
    gint w;
} ProgressBar;

ProgressBar *initialiser_ProgressBar(GtkWidget *pere, gdouble dfr, gdouble unt, gint w, gint h);
void progression_animation(ProgressBar *pWidget, gpointer data);
void OnButton(ProgressBar *pWidget, gpointer data);
void add_progress_bar(GtkWidget *pere, gdouble dfr, gdouble unite, gint x, gint y, gboolean type, gint w, gint h);

#endif // PROG_BAR_H_INCLUDED
