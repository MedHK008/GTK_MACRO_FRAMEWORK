#ifndef BOITE_DIALOG_H_INCLUDED
#define BOITE_DIALOG_H_INCLUDED


// Structure repr�sentant une bo�te de dialogue
typedef struct {
    GtkWidget *dialogue;        // Le widget de la bo�te de dialogue GTK
    GtkWidget *zone_contenu;    // Le widget de la zone de contenu de la bo�te de dialogue
    GtkWindow *parent;          // La fen�tre parente de la bo�te de dialogue
    gchar *titre;               // Le titre de la bo�te de dialogue
    gchar *icone;               // Le chemin vers l'ic�ne de la bo�te de dialogue
    gint modal;                 // Indique si la bo�te de dialogue est modale (TRUE) ou non modale (FALSE)
    gint hauteur;               // La hauteur de la bo�te de dialogue
    gint largeur;               // La largeur de la bo�te de dialogue
    gint position;              // La position de la bo�te de dialogue sur l'�cran (par exemple, GTK_WIN_POS_CENTER)
    gint etat;                  // L'�tat de la bo�te de dialogue (0: normal, 1: actif, 2: pr�-s�lectionn�, 3: s�lectionn�, 4: insensible)
    gchar *couleur_fond;        // La couleur de fond de la bo�te de dialogue
} BoiteDialogue;

// Fonction pour cr�er et initialiser une structure BoiteDialogue
BoiteDialogue *creer_initialiser_boite_dialogue(GtkWindow *parent, gchar *titre, gchar *icone, guint modal, gint hauteur, gint largeur, gint etat, gchar *couleur_fond) {
    // Allouer de la m�moire pour la structure BoiteDialogue
    BoiteDialogue *BD = (BoiteDialogue *)g_malloc(sizeof(BoiteDialogue));
    BD->zone_contenu = NULL; // Initialiser le pointeur de la zone de contenu � NULL
    BD->dialogue = NULL; // Initialiser le pointeur du dialogue � NULL
    BD->icone = NULL; // Initialiser le pointeur de l'ic�ne � NULL
    BD->titre = NULL; // Initialiser le pointeur du titre � NULL

    if (!BD) { // V�rifier si l'allocation de m�moire a �chou�
        printf("\nERREUR\n"); // Afficher un message d'erreur
        exit(-1); // Quitter le programme avec un code d'erreur
    }

    if (titre) { // V�rifier si le titre est d�fini
        BD->titre = g_strdup(titre); // Dupliquer la cha�ne de caract�res du titre
        if (!BD->titre) { // V�rifier si la duplication a �chou�
            printf("\nERREUR\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    if (icone) { // V�rifier si l'ic�ne est d�finie
        BD->icone = g_strdup(icone); // Dupliquer la cha�ne de caract�res de l'ic�ne
        if (!BD->icone) { // V�rifier si la duplication a �chou�
            printf("\nErreur\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    if (couleur_fond) { // V�rifier si la couleur de fond est d�finie
        BD->couleur_fond = g_strdup(couleur_fond); // Dupliquer la cha�ne de caract�res de la couleur de fond
        if (!BD->couleur_fond) { // V�rifier si la duplication a �chou�
            printf("\nERREUR\n"); // Afficher un message d'erreur
            exit(-1); // Quitter le programme avec un code d'erreur
        }
    }

    BD->parent = parent; // Affecter la fen�tre parente
    BD->modal = modal; // Indiquer si la bo�te de dialogue est modale
    BD->hauteur = hauteur; // D�finir la hauteur de la bo�te de dialogue
    BD->largeur = largeur; // D�finir la largeur de la bo�te de dialogue

    return BD; // Retourner la structure BoiteDialogue initialis�e
}

// Fonction pour d�finir les attributs visuels de la bo�te de dialogue
void definir_attributs_boite_dialogue(BoiteDialogue *BD) {
    GdkRGBA couleur; // D�claration d'une structure de couleur GTK
    BD->dialogue = gtk_dialog_new(); // Cr�er une nouvelle bo�te de dialogue GTK
    gtk_window_set_title(GTK_WINDOW(BD->dialogue), BD->titre); // D�finir le titre de la bo�te de dialogue
    gtk_window_set_icon_from_file(GTK_WINDOW(BD->dialogue), BD->icone, NULL); // D�finir l'ic�ne de la bo�te de dialogue � partir d'un fichier
    BD->zone_contenu = gtk_fixed_new(); // Obtenir la zone de contenu de la bo�te de dialogue
    gtk_widget_set_size_request(BD->dialogue, BD->largeur, BD->hauteur); // D�finir la taille de la bo�te de dialogue
    gtk_window_set_transient_for(GTK_WINDOW(BD->dialogue), GTK_WINDOW(BD->parent)); // D�finir la fen�tre parente de la bo�te de dialogue

    if (BD->modal == 1) // V�rifier si la bo�te de dialogue est modale
        gtk_window_set_modal(GTK_WINDOW(BD->dialogue), TRUE); // D�finir la bo�te de dialogue comme modale

    gdk_rgba_parse(&couleur, BD->couleur_fond); // Convertir la couleur de fond en format GTK

    // Appliquer la couleur de fond en fonction de l'�tat de la bo�te de dialogue
    switch (BD->etat) {
    case 0: // �tat normal
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_NORMAL, &couleur);
        break;
    case 1: // �tat actif
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_ACTIVE, &couleur);
        break;
    case 2: // �tat de surbrillance
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_PRELIGHT, &couleur);
        break;
    case 3: // �tat s�lectionn�
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_SELECTED, &couleur);
        break;
    case 4: // �tat insensible
        gtk_widget_override_background_color(BD->dialogue, GTK_STATE_FLAG_INSENSITIVE, &couleur);
        break;
    }
}
BoiteDialogue* Add_boite_dialogue(GtkWindow *parent, gchar *titre, gchar *icone, guint modal, gint hauteur, gint largeur, gint etat, gchar *couleur_fond)
{
    BoiteDialogue*bd=creer_initialiser_boite_dialogue(parent,titre,icone,modal,hauteur,largeur,etat,couleur_fond);
    definir_attributs_boite_dialogue(bd);
    return (BoiteDialogue*)(bd);

}
// Fonction pour ajouter un bouton � une bo�te de dialogue
void ajouter_a_boite_dialogue(BoiteDialogue*dialogue,GtkWidget*element , gint x , gint y) {
    if (dialogue && element) // V�rifier si le libell� du bouton et la bo�te de dialogue sont d�finis
        gtk_fixed_put(dialogue->zone_contenu,element,x,y); // Ajouter un bouton avec le libell� sp�cifi� et la r�ponse associ�e � la bo�te de dialogue
}

// Fonction pour ajouter une action � une bo�te de dialogue
//GTK_RESPONSE_NONE : -1
//GTK_RESPONSE_REJECT : -2
//GTK_RESPONSE_ACCEPT : -3
//GTK_RESPONSE_DELETE_EVENT : -4
//GTK_RESPONSE_OK : -5
//GTK_RESPONSE_CANCEL : -6
//GTK_RESPONSE_CLOSE : -7
//GTK_RESPONSE_YES : -8
//GTK_RESPONSE_NO : -9
//GTK_RESPONSE_APPLY : -10
//GTK_RESPONSE_HELP : -11
void ajouter_action_a_boite_dialogue(BoiteDialogue *dialogue, GtkWidget *widget, gint reponse) {
    if (widget && dialogue) // V�rifier si le widget et la bo�te de dialogue sont d�finis
        gtk_dialog_add_action_widget(dialogue->dialogue, widget, reponse); // Ajouter une action associ�e au widget � la bo�te de dialogue
}
void on_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_widget_show_all(GTK_WIDGET(data));
}


#endif // BOITE_DIALOG_H_INCLUDED
