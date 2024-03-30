#include "headers.h"




int main(int argc, char *argv[]) {
    debut_programme(argc,argv);
    Fenetre* ma_fenetre = add_window("fuck","gtklogo.png","fuck you","#FFFFFF",3840,2160,GTK_WIN_POS_CENTER,10,10,1,TRUE);

    Fixed* fixed = exemple();


    ButtonSimple* B=add_button("ff","ff",NULL,50,40,NULL,NULL,NULL);
    add_widget_to_fixed(fixed,B->button,400,400);
    BoiteDialogue* BD=Add_boite_dialogue(ma_fenetre->window,"fuck","gtklogo.png",1,300,200,"#FFFFFF");
    ajouter_button_boide_dialogue(BD,"fuck",2);
    declencher_boite_dialogue(BD,B->button);

    Add_Entry(fixed->fixed,"fuck",500,0,0,1,'*',200,50,"#FFFFFF",500,400);




    ///matqissch hadchi li mor had lcomment
    add_to_window(fixed->fixed,ma_fenetre->window);
    gtk_widget_show_all(ma_fenetre->window);


    fin_programme(ma_fenetre);
    return 0;
}
