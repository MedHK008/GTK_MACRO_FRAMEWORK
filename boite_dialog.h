#ifndef BOITE_DIALOG_H_INCLUDED
#define BOITE_DIALOG_H_INCLUDED

// Structure représentant une boîte de dialogue
typedef struct {
    GtkWidget *dialogue;        // Le widget de la boîte de dialogue GTK
    GtkWidget *zone_contenu;    // Le widget de la zone de contenu de la boîte de dialogue
    GtkWindow *parent;          // La fenêtre parente de la boîte de dialogue
    gchar *titre;               // Le titre de la boîte de dialogue
    gchar *icone;               // Le chemin vers l'icône de la boîte de dialogue
    gint modal;                 // Indique si la boîte de dialogue est modale (TRUE) ou non modale (FALSE)
    gint hauteur;               // La hauteur de la boîte de dialogue
    gint largeur;               // La largeur de la boîte de dialogue
    gchar *couleur_fond;        // La couleur de fond de la boîte de dialogue
} BoiteDialogue;

// Fonction pour créer et initialiser une structure BoiteDialogue
BoiteDialogue *creer_initialiser_boite_dialogue(GtkWindow *parent, gchar *titre, gchar *icone, guint modal, gint hauteur, gint largeur, gchar *couleur_fond) {
    // Allouer de la mémoire pour la structure BoiteDialogue
    BoiteDialogue *BD = (BoiteDialogue *)g_malloc(sizeof(BoiteDialogue));
    BD->zone_contenu = NULL; // Initialiser le pointeur de la zone de contenu à NULL
    BD->dialogue = NULL; // Initialiser le pointeur du dialogue à NULL
    BD->icone = NULL; // Initialiser le pointeur de l'icône à NULL
    BD->titre = NULL; // Initialiser le pointeur du titre à NULL

    if (!BD) { // Vérifier si l'allocation de mémoire a échoué
        printf("\nERREUR\n"); // Afficher un message d'erreur
        exit(-1); // Quitter le programme avec un code d'erreur
    }

    if (titre) { // Vérifier si le titre est défini
        BD->titre = g_strdup(titre); // Dupliquer la chaîne de caractères du titre
        if (!BD->titre) { // Vérifier si la duplication a échoué
            printf("\nERREUR\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    if (icone) { // Vérifier si l'icône est définie
        BD->icone = g_strdup(icone); // Dupliquer la chaîne de caractères de l'icône
        if (!BD->icone) { // Vérifier si la duplication a échoué
            printf("\nErreur\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    if (couleur_fond) { // Vérifier si la couleur de fond est définie
        BD->couleur_fond = g_strdup(couleur_fond); // Dupliquer la chaîne de caractères de la couleur de fond
        if (!BD->couleur_fond) { // Vérifier si la duplication a échoué
            printf("\nERREUR\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    BD->parent = parent; // Affecter la fenêtre parente
    BD->modal = modal; // Indiquer si la boîte de dialogue est modale
    BD->hauteur = hauteur; // Définir la hauteur de la boîte de dialogue
    BD->largeur = largeur; // Définir la largeur de la boîte de dialogue

    return BD; // Retourner la structure BoiteDialogue initialisée
}

// Fonction pour définir les attributs visuels de la boîte de dialogue
void definir_attributs_boite_dialogue(BoiteDialogue*BD)
{
     GdkRGBA couleur;


    BD->dialogue=gtk_dialog_new();

    if(BD->titre)



        gtk_window_set_title(GTK_WINDOW(BD->dialogue),BD->titre);

    if(BD->modal)
    {


        gtk_window_set_modal(GTK_WINDOW(BD->dialogue),TRUE);

        }
    if(BD->parent)
        gtk_window_set_transient_for(GTK_WINDOW(BD->dialogue), GTK_WINDOW(BD->parent));
    if(BD->largeur>0 && BD->hauteur>0)
        gtk_window_set_default_size(GTK_WINDOW(BD->dialogue), BD->largeur,BD->hauteur);
    if(BD->icone)
        {
        GdkPixbuf *icon = gdk_pixbuf_new_from_file(BD->icone, NULL);
        GList *icon_list = NULL;
        icon_list = g_list_append(icon_list, icon);
        gtk_window_set_icon_list(GTK_WINDOW(BD->dialogue), icon_list);



        }
    GtkWidget*content =gtk_dialog_get_content_area(GTK_DIALOG(BD->dialogue));
    BD->zone_contenu=gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(content),BD->zone_contenu);
    if(BD->couleur_fond)
    {
        gdk_rgba_parse(&couleur, BD->couleur_fond); // Convertir la couleur de fond en format GTK
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_NORMAL, &couleur);
    }





}

BoiteDialogue* Add_boite_dialogue(GtkWindow *parent, gchar *titre, gchar *icone, guint modal, gint hauteur, gint largeur, gchar *couleur_fond)
{
    BoiteDialogue*bd=creer_initialiser_boite_dialogue(parent,titre,icone,modal,hauteur,largeur,couleur_fond);

    definir_attributs_boite_dialogue(bd);

    return (BoiteDialogue*)(bd);

}
// Fonction pour ajouter un bouton à une boîte de dialogue
void ajouter_a_boite_dialogue(BoiteDialogue*dialogue,GtkWidget*element , gint x , gint y) {
    if (dialogue && element) 
        gtk_fixed_put(GTK_FIXED(dialogue->zone_contenu),element,x,y); // Ajouter un bouton avec le libellé spécifié et la réponse associée à la boîte de dialogue
}
void ajouter_button_boide_dialogue(BoiteDialoge*dialogue,gchar*libelle,gint reponse){
    if(dialogue && libelle)
             gtk_dialog_add_button(GTK_DIALOG(BD->boite),libelle,repose);

}

void on_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_widget_show_all(GTK_WIDGET(data));
}
void declencher_boite_dialogue(BoiteDialogue*BD ,GtkWidget*button)
{
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked),BD->dialogue);

}

#endif // BOITE_DIALOG_H_INCLUDED
