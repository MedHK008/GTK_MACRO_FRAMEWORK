#include "ProgressBar.h"

ProgressBar *initialiser_ProgressBar(GtkWidget *pere, gdouble dfr, gdouble unt, gint w, gint h)
{
    ProgressBar *pb = (ProgressBar *)g_malloc(sizeof(ProgressBar));
    pb->widget = gtk_progress_bar_new();
    pb->parent = pere;
    pb->w = w;
    pb->h = h;
    if (pb->w || pb->h)
        gtk_widget_set_size_request(pb->widget, pb->w, pb->h);
    pb->unite = unt;
    pb->fraction = dfr;
    return pb;
}

void progression_animation(ProgressBar *pWidget, gpointer data)
{
    gdouble dFraction;
    gint i = (pWidget->fraction * 2000);
    gint iTotal = 2000;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pWidget->widget), pWidget->fraction);
    gtk_grab_add(pWidget->widget);
    printf("D�but de l'animation de progression\n");
    for (i; i < iTotal; ++i)
    {
        dFraction = (gdouble)i / (gdouble)iTotal;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pWidget->widget), dFraction);
        gtk_main_iteration();
    }
    gtk_grab_remove(pWidget->widget);
}

void OnButton(ProgressBar *pWidget, gpointer data)
{
    gdouble valeurCourante = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(pWidget->widget));
    valeurCourante += pWidget->unite;
    if (valeurCourante > 1.0)
        valeurCourante = 0.0;
    pWidget->fraction = valeurCourante;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pWidget->widget), valeurCourante);
}

void add_progress_bar(GtkWidget *pere, gdouble dfr, gdouble unite, gint x, gint y, gboolean type, gint w, gint h)
{
    ProgressBar *bar = initialiser_ProgressBar(pere, dfr, unite, w, h);
    GtkWidget *pVBox = gtk_vbox_new(FALSE, 10);
    gtk_box_pack_start(GTK_BOX(pVBox), bar->widget, TRUE, FALSE, 0);
    switch (type)
    {
    case 0:
    case 1:
        GtkWidget *pButton = gtk_button_new_with_label("ajouter unite");
        gtk_box_pack_start(GTK_BOX(pVBox), pButton, TRUE, FALSE, 0);
        g_signal_connect_swapped(G_OBJECT(pButton), "clicked", G_CALLBACK(OnButton), bar);
        if (type == 1)
            break;
    case 2:
        GtkWidget *pButton1 = gtk_button_new_with_label(GTK_STOCK_REFRESH);
        gtk_box_pack_start(GTK_BOX(pVBox), pButton1, TRUE, FALSE, 0);
        g_signal_connect_swapped(G_OBJECT(pButton1), "clicked", G_CALLBACK(progression_animation), bar);
        break;
    }
    gtk_fixed_put(pere, pVBox, x, y);
}