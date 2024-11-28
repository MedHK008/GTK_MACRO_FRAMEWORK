// This project requires the installation of the GTK3 library. Look it up on youtube, work on codeBlocks for the simplest installation.
// CLion IDE is good too, but it requires a little more work to install the GTK3 library. and you will need to install the CMake tool.

#include "headers/headers.h"

void debut_programme(int argc,char*argv[]);
void fin_programme(Fenetre* ma_fenetre);
Fixed* exemple();
void add_buttons();


int main(int argc, char *argv[]) 
{
    /// Initialiser le programme
    debut_programme(argc,argv);

    /// Initialiser la fenetre
    Fenetre* ma_fenetre = add_window("example window",GTKLOGO,"bizo","#FFFFFF",1000,800,GTK_WIN_POS_CENTER,10,10,1,TRUE);

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


Fixed* exemple()
{
    /****************************************************** les bouttons***********************************/
        Fixed* fixed0=init_gtk_fixed();
    /******************************************************boutton normal***********************************/
    /// les parametres : le fixed , le label du button , path de l'image utiliser (NULL s'il y a pas d'image),height,width,bgcolor, x , y
        texte* txt_button=initialiser_texte(20,30,"exemple des boutons",3,"Verdana",12,"italic",NULL,"#000000","#FFFFFF",NULL);
        add_label(fixed0->fixed,txt_button,TRUE,FALSE,50,0);
        SimpleButton *button = add_button("boutton1","first",GTKLOGO,100,100,"#FF0000",50,50);
        add_widget_to_fixed(fixed0,button->button,50,50);

    /******************************************************boutton normal***********************************/
    /****************************************************** les cochers***********************************/
    /// les parametres : le fixed , le label , le x , le y ,le bgcolor, si le checkbox est cocher d�s le d�but ou non
        texte* txt_cocher=initialiser_texte(20,30,"exemple des bouttons a cocher",3,"Verdana",12,"italic",NULL,"#000000","#FFFFFF",NULL);
        add_label(fixed0->fixed,txt_cocher,TRUE,FALSE,50,280);
        // Initialize the checkbox list
        CheckboxList *checkboxList = init_checkbox_list();

        GtkWidget *checkbox1 = add_cocher(checkboxList,fixed0->fixed, "testing cocher1", 200, 300,NULL, TRUE,"coche1");
        GtkWidget *checkbox2 = add_cocher(checkboxList,fixed0->fixed, "testing cocher2", 200, 330, "#FFFFFF", TRUE,"coche2");
        GtkWidget *checkbox3 = add_cocher(checkboxList,fixed0->fixed, "testing cocher3", 200, 360, "#FFFFFF", TRUE,"coche3");
        GtkWidget *checkbox4 = add_cocher(checkboxList,fixed0->fixed, "testing cocher4", 200, 390, "#FFFFFF", TRUE,"coche4");

        // Add the checkboxes to the fixed container
        add_widget_to_fixed(fixed0,checkbox1, 200, 300);
        add_widget_to_fixed(fixed0,checkbox2, 200, 330);
        add_widget_to_fixed(fixed0,checkbox3, 200, 360);
        add_widget_to_fixed(fixed0,checkbox4, 200, 390);


    /****************************************************** les cochers***********************************/
    /****************************************************** les radios***********************************/
    /// les parametres : le fixed  , le x , le y , les labels,le bgcolor de chaque button, le radio qui soit cocher d�s le d�but (all FALSE signifie que aucun ne sera cocher)
        texte* txt_radio=initialiser_texte(20,30,"exemple des bouttons radio",3,"Verdana",12,"italic",NULL,"#000000","#FFFFFF",NULL);
        add_label(fixed0->fixed,txt_radio,TRUE,FALSE,50,430);
    //    char *labels2[NB_RADIO] = {"Option 1", "Option 2", "Option 3"};
    //    char *colors2[NB_RADIO] = {"#FFFFFF", "#FFFFFF", "#FFFFFF"};
    //    gboolean checked2[NB_RADIO] = {FALSE, FALSE, FALSE};
        GtkWidget *radioBox = add_radio(3, 20, 30, (char *[]){"Option 1", "Option 2", "Option 3"},(char *[]){"#FF00FF","#00FF00","#FFFF00"},
                                        (gboolean[]){TRUE, FALSE, FALSE},(gchar *[]){"radio1", "radio2", "radio3"},FALSE);
        add_widget_to_fixed(fixed0,radioBox,200,450);
    /****************************************************** les radios***********************************/
    /****************************************************** les spins***********************************/
    ///khdem biha wskot mafiya li ykteb lcommentaire db
        texte* txt_spin=initialiser_texte(20,30,"exemple boutton spin",3,"Verdana",12,"italic",NULL,"#000000","#FFFFFF",NULL);
        add_label(fixed0->fixed,txt_spin,TRUE,FALSE,50,570);
        SpinButton* spin=add_spin(50, 650, 0.0, 100.0, 1.0, 1.0, 30, 150, 1, 2, 1, 1, "#00ff00", 1.0,"spin1");
        add_widget_to_fixed(fixed0,spin->SpinButton,200,600);
    /****************************************************** les spins***********************************/
    /***********************************************les bouttons fin*****************************************/
    return ((Fixed*)fixed0);
}


void add_buttons()
{
    /****************************************************** les bouttons***********************************/


    /******************************************************boutton normal***********************************/
    /// les parametres : le fixed , le label du button , path de l'image utiliser (NULL s'il y a pas d'image),height,width,bgcolor, x , y
        add_label(fixed,txt_button,TRUE,FALSE,50,50);
        add_button(fixed,"first",GTKLOGO,100,100,"#FF0000",50,100,50,50);
        add_button(fixed,NULL,GTKLOGO,100,100,"#FF0000",290,100,150,150);
    /******************************************************boutton normal***********************************/




    /****************************************************** les cochers***********************************/
    /// les parametres : le fixed , le label , le x , le y ,le bgcolor, si le checkbox est cocher d�s le d�but ou non
        add_label(fixed,txt_cocher,TRUE,FALSE,50,250);
        add_cocher(fixed,"testing cocher1",200,300,"#FFFFFF",TRUE);
        add_cocher(fixed,"testing cocher2",200,330,"#FFFFFF",TRUE);
        add_cocher(fixed,"testing cocher3",200,360,"#FFFFFF",TRUE);
        add_cocher(fixed,"testing cocher4",200,390,"#FFFFFF",TRUE);
    /****************************************************** les cochers***********************************/



    /****************************************************** les radios***********************************/
    /// les parametres : le fixed  , le x , le y , les labels,le bgcolor de chaque button, le radio qui soit cocher d�s le d�but (all FALSE signifie que aucun ne sera cocher)
        add_label(fixed,txt_radio,TRUE,FALSE,50,450);
        char *labels2[NB_RADIO] = {"Option 1", "Option 2", "Option 3"};
        char *colors2[NB_RADIO] = {"#FFFFFF", "#FFFFFF", "#FFFFFF"};
        gboolean checked2[NB_RADIO] = {FALSE, FALSE, FALSE};
        add_radio(fixed, NB_RADIO,250,500, labels2, colors2,checked2);
    /****************************************************** les radios***********************************/


    /****************************************************** les spins***********************************/
    ///khdem biha wskot mafiya li ykteb lcommentaire db
        add_label(fixed,txt_spin,TRUE,FALSE,50,600);
        add_spin(fixed, 50, 650, 0.0, 100.0, 1.0, 1.0, 30, 150, 1, 2, 1, 1, "#00ff00", 1.0);
        add_spin(fixed, 250, 650, 0.0, 100.0, 50.0, 5.0, 30, 30, 1, 2, 1, 1, "#ff0000", 1.0);
        add_spin(fixed, 450, 650, 0.0, 100.0, 100.0, 100.0, 50, 150, 1, 2, 1, 1, "#ffffff", 1.0);
        add_Tab(notebook,fixed,"Tab 1","#FF00FF");
    /****************************************************** les spins***********************************/


    /***********************************************les bouttons fin*****************************************/
}

