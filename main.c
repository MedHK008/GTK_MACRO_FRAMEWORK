#include "headers.h"




int main(int argc, char *argv[]) {
    debut_programme(argc,argv);
    Fenetre* ma_fenetre = add_window("fuck","gtklogo.png","fuck you","#FFFFFF",3840,2160,GTK_WIN_POS_CENTER,10,10,1,TRUE);

    Fixed* fixed = exemple();


    ButtonSimple* B1=add_button("fff","fff",NULL,50,40,NULL,NULL,NULL);
    add_widget_to_fixed(fixed,B1->button,400,400);
    Boite_message* BM=Add_Boite_Message(ma_fenetre->window,"BM",0,NULL,NULL,300,100);
    ButtonSimple* B=add_button("ff","ff",NULL,50,40,NULL,NULL,NULL);
    ajouter_to_boite_message(BM,B->button,50,50);
    declencher_boite_message(BM,B1->button);
    Add_Entry(BM->fixed,"fuck",500,0,0,1,'*',200,50,"#FFFFFF",100,100);




    ///matqissch hadchi li mor had lcomment
    add_to_window(fixed->fixed,ma_fenetre->window);
    gtk_widget_show_all(ma_fenetre->window);


    fin_programme(ma_fenetre);
    return 0;
}
