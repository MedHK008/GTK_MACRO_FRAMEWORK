#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <gtk/gtk.h>

// Structure pour représenter un cadre (frame) avec des éléments associés
typedef struct
{
    GtkWidget *widget;          // Le widget GTK représentant le cadre
    GtkWidget *parent;          // Le parent du cadre
    gint xligne;                // Position horizontale de l'étiquette dans le cadre
    gint yligne;                // Position verticale de l'étiquette dans le cadre
    texte *text;                // Structure de texte associée au cadre
    GtkWidget *conteneur;       // Le conteneur associé au cadre (peut être un label ou autre)
    GtkShadowType type;         // Type d'ombre du cadre
} frame;

// Fonction pour initialiser une structure de cadre avec des paramètres spécifiés
frame *initialiser_frame(GtkWidget *pere, gint x, gint y, texte *t, GtkWidget *fils, GtkShadowType type);

// Fonction pour créer un cadre en utilisant les paramètres spécifiés dans la structure
void creer_frame(frame *fr);

frame *add_frame(GtkWidget *pere, gfloat xligne, gfloat yligne, texte *tx, GtkWidget *fils, GtkShadowType type, gint x, gint y);

#endif // FRAME_H_INCLUDED
