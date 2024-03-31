#ifndef BOITE_MESSAGE_H_INCLUDED
#define BOITE_MESSAGE_H_INCLUDED
// Structure représentant une boîte de message
typedef struct {
    GtkWidget *message_box;
    GtkWidget *parent;
    GtkWidget*fixed ;
    gchar *titre;
    gchar *icon;
    gchar *color;
    gint modal ;
    gint h ;
    gint w ;

} Boite_message;

// Fonction pour initialiser une boîte de message
Boite_message *initialiser_boite_message() {
    Boite_message *BM = g_malloc(sizeof(Boite_message));
    if (!BM) exit(-1);

    BM->message_box = NULL;
    BM->parent = NULL;
    BM->titre = NULL;
    BM->color=NULL;
    BM->icon=NULL;
    BM->modal=0;
    BM->h=0;
    BM->w=0;


    return BM;
}
Boite_message*set_attribue(Boite_message*BM,GtkWidget*parent ,gchar*titre ,gint modal,gchar*color,gchar *icon ,gint w,gint h)
{
     if(titre)
    {
        BM->titre=(gchar*)g_malloc(sizeof(gchar)*50);
        strcpy(BM->titre,titre);
    }
    if(color)
    {
        BM->color=(gchar*)g_malloc(sizeof(gchar)*50);
        strcpy(BM->color,color);
    }
    if(icon)
    {
        BM->icon=(gchar*)g_malloc(sizeof(gchar)*50);
        strcpy(BM->icon,icon);
    }
        BM->parent=parent;
        BM->modal=modal;
    if(h>0 && w>0)
    {
        BM->h=h;
        BM->w=w;
    }
    return BM;


}
// Fonction pour définir les attributs de la boîte de message
void definir_attribut_boite_message(Boite_message *BM) {
    BM->message_box = gtk_message_dialog_new(GTK_WINDOW(BM->parent),
                                             GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE
                                             ,NULL, NULL);
    if(BM->titre)
        gtk_window_set_title(GTK_WINDOW(BM->message_box), BM->titre);

    GtkWidget*content= gtk_dialog_get_content_area(GTK_DIALOG(BM->message_box));
   BM->fixed=gtk_fixed_new();
   gtk_container_add(GTK_CONTAINER(content),BM->fixed);
    gtk_widget_set_size_request(BM->message_box,BM->w,BM->h);
      if(BM->color)
    {

        GdkRGBA couleur;
        gdk_rgba_parse(&couleur, BM->color); // Convertir la couleur de fond en format GTK

        gtk_widget_override_background_color(BM->message_box, GTK_STATE_FLAG_NORMAL, &couleur);

    }
      if(BM->icon)
    {


    GdkPixbuf *icon = gdk_pixbuf_new_from_file(BM->icon, NULL);
    if (icon != NULL) {
        gtk_window_set_icon(GTK_WINDOW(BM->message_box), icon);
        g_object_unref(icon); // Free the icon's resources when it's no longer needed
    }
     }
}

// Fonction pour lire les attributs de la boîte de message à partir d'un fichier




Boite_message*Add_Boite_Message(GtkWidget*parent,gchar *titre ,gint modal ,gchar *color,gchar*icon,gint w, gint h)
{
    Boite_message *BM = initialiser_boite_message();
    BM=set_attribue(BM,parent,titre,modal,color,icon,w,h);
    definir_attribut_boite_message(BM);

    return BM;
}
void ajouter_to_boite_message(Boite_message*BM,GtkWidget*widget,gint x, gint y)
{
    if(BM && widget)
        gtk_fixed_put(GTK_FIXED(BM->fixed),widget,x,y);
}

void on_button_clicked_Boite_Message(GtkWidget *widget, gpointer data) {
    gtk_widget_show_all(GTK_WIDGET(data));
}

void declencher_boite_message(Boite_message*BM,GtkWidget*button)
{
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked_Boite_Message), BM->message_box);

}

#endif // BOITE_MESSAGE_H_INCLUDED
