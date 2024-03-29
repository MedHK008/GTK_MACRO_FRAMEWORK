#include "headers.h"




int main(int argc, char *argv[]) {
    debut_programme(argc,argv);
    Fenetre* ma_fenetre = add_window();

    GtkWidget *fixed = exemple();

    ///matqissch hadchi li mor had lcomment
    add_to_window(fixed,ma_fenetre->window);
    gtk_widget_show_all(ma_fenetre->window);

    fin_programme(ma_fenetre);
    return 0;
}
