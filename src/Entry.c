#include "Entry.h"

Saisie *creer_initialiser_saisie(gchar *placeholder, gint longueur_max, gfloat alignement_x, gint visible, gint caractere_visible, guchar carac_vis, gint w, gint h, gchar *couleur_fond) {
    // Allouer de la mémoire pour la structure Saisie
    Saisie *saisie = (Saisie *)g_malloc(sizeof(Saisie));
    if (!saisie) { // Vérifier si l'allocation de mémoire a réussi
        printf("\Erreur\n"); // Afficher un message d'erreur
        exit(0); // Quitter le programme avec un code d'erreur
    }
    if (placeholder) { // Vérifier si le paramètre placeholder est défini
        saisie->placeholder = g_strdup(placeholder); // Dupliquer la chaîne placeholder
        if (!saisie->placeholder) { // Vérifier si la duplication a réussi
            printf("\nErreur\n"); // Afficher un message d'erreur
            exit(0); // Quitter le programme avec un code d'erreur
        }
    }
    saisie->couleur_fond = g_strdup(couleur_fond); // Dupliquer la couleur de fond

    // Initialiser les autres attributs de la structure Saisie
    saisie->hauteur = h; // Hauteur de la zone de saisie
    saisie->largeur = w; // Largeur de la zone de saisie
    saisie->alignement_x = alignement_x; // Alignement horizontal de la zone de saisie
    saisie->visible = visible; // Visibilité de la zone de saisie
    saisie->caractere_visible = caractere_visible; // Visibilité des caractères saisis
    saisie->caractere = carac_vis; // Caractère utilisé pour masquer les saisies
    saisie->longueur_max = longueur_max; // Longueur maximale de la saisie
    return saisie; // Retourner la structure Saisie initialisée
}

void definir_attributs_saisie(Saisie *e) {
    GdkRGBA couleur;
    e->entree = gtk_entry_new(); // Créer une nouvelle zone de saisie GTK
    if (e->couleur_fond)
        gdk_rgba_parse(&couleur, e->couleur_fond); // Convertir la couleur de fond en format GTK
    // Définir le texte de substitution de la zone de saisie
    gtk_entry_set_placeholder_text(GTK_ENTRY(e->entree), e->placeholder);
    // Définir la longueur maximale de la saisie
    gtk_entry_set_max_length(GTK_ENTRY(e->entree), e->longueur_max);
    // Définir l'alignement horizontal de la zone de saisie
    gtk_entry_set_alignment(GTK_ENTRY(e->entree), e->alignement_x);

    // Masquer ou afficher le texte saisi en fonction de la visibilité
    if (!e->visible) {
        gtk_entry_set_visibility(GTK_ENTRY(e->entree), FALSE);
    }

    // Définir le caractère utilisé pour masquer les saisies si nécessaire
    if (e->caractere_visible == 1) {
        gtk_entry_set_invisible_char(GTK_ENTRY(e->entree), e->caractere);
    }

    // Définir la taille de la zone de saisie si des valeurs positives sont spécifiées
    if (e->largeur > 0 && e->hauteur > 0) {
        gtk_widget_set_size_request(e->entree, e->largeur, e->hauteur);
    }

    // Appliquer la couleur de fond en fonction de l'état de la zone de saisie
    if (e->couleur_fond) {
        gdk_rgba_parse(&couleur, e->couleur_fond); // Convertir la couleur de fond en format GTK
        gtk_widget_override_background_color(e->entree, GTK_STATE_FLAG_NORMAL, &couleur);
    }
}

void Add_Entry(GtkWidget* fixed, gchar *placeholder, gint longueur_max, gfloat alignement_x, gint visible, gint caractere_visible, guchar carac_vis, gint w, gint h, gchar *couleur_fond, gint x, gint y) {
    Saisie *E = creer_initialiser_saisie(placeholder, longueur_max, alignement_x, visible, caractere_visible, carac_vis, w, h, couleur_fond);
    definir_attributs_saisie(E);
    gtk_fixed_put(GTK_FIXED(fixed), E->entree, x, y);
}
