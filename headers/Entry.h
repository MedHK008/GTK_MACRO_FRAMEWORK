#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

// Structure représentant une zone de saisie
typedef struct {
    GtkWidget *entree;          // Le widget de la zone de saisie GTK
    gchar *placeholder;         // Le texte de substitution affiché lorsqu'il n'y a pas de texte
    gint longueur_max;          // Le nombre maximal de caractères pouvant être saisis
    gfloat alignement_x;        // L'alignement horizontal du texte (0 pour à gauche, 1 pour à droite)
    gint visible;               // Indique si le texte saisi est visible (TRUE) ou caché (FALSE)
    gint caractere_visible;     // Indique si un caractère spécifique est utilisé pour masquer le texte saisi
    guchar caractere;           // Le caractère utilisé pour masquer le texte saisi (si caractere_visible est TRUE)
    gint hauteur;               // La hauteur de la zone de saisie
    gint largeur;               // La largeur de la zone de saisie
    gchar *couleur_fond;        // La couleur de fond de la zone de saisie
} Saisie;

// Fonction pour créer et initialiser une structure Saisie
Saisie *creer_initialiser_saisie(gchar *placeholder, gint longueur_max, gfloat alignement_x, gint visible, gint caractere_visible, guchar carac_vis, gint w, gint h, gchar *couleur_fond);

// Fonction pour définir les attributs visuels de la zone de saisie
void definir_attributs_saisie(Saisie *e);

void Add_Entry(GtkWidget* fixed, gchar *placeholder, gint longueur_max, gfloat alignement_x, gint visible, gint caractere_visible, guchar carac_vis, gint w, gint h, gchar *couleur_fond, gint x, gint y);

#endif // ENTRY_H_INCLUDED
