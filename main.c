///les bibliothèque systeme
#include <gtk/gtk.h>
#include <gdk/gdk.h>

///les constante
#define NBC 100
#define NB_RADIO 3

///les bibliothèque des widgets
#include "window.h"
#include "ex_buttons.h"


void debut_programme(int argc,char*argv[]);
void fin_programme(Fenetre* ma_fenetre);


int main(int argc, char *argv[]) 
{
    /// Initialiser le programme
    debut_programme(argc,argv);

    /// Initialiser la fenetre
    Fenetre* ma_fenetre = add_window("example window","gtklogo.png","bizo","#FFFFFF",1000,800,GTK_WIN_POS_CENTER,10,10,1,TRUE);

    /// Ajouter les widgets
    Fixed* fixed = exemple();

    /// Terminer le programme par la fermeture de la fenetre
    fin_programme(ma_fenetre);

    return 0;
}

void debut_programme(int argc,char*argv[]){
    gtk_init(&argc,&argv);
}

void fin_programme(Fenetre* ma_fenetre)
{
    g_signal_connect(G_OBJECT(ma_fenetre->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
}
