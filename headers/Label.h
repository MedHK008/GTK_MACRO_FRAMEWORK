#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include <gtk/gtk.h>

typedef struct
{
     gchar text[200];
     guint alignement;/* L'alignement du texte
    1: GTK_JUSTIFY_LEFT pour aligner le texte � gauche (par d�faut);
    2: GTK_JUSTIFY_RIGHT pour aligner le texte � droite ;
    3: GTK_JUSTIFY_CENTER pour centrer le texte ;
    4:GTK_JUSTIFY_FILL pour justifier�le�texte*/
    gint w; // Largeur
    gint h; // Hauteur
    gchar police[30];//Pour definir la police utils�e*/
    gint taille_text;/* Pour definir la taille du texte*/
    gchar style[15];//Pour definir le style du texte*/
    gchar epaisseur[15]; /*Pour definir l'epaisseur du texte : small , large , Xlaarge... */
    gchar couleur_text[15];//Pour definir la couleur du texte*/
    gchar couleur_fond[15];//Pour definir la couleur du fond*/
    gchar underline[15];/* Pour le soulignement du texte*/
    gboolean line_through; //Pour barrer le texte/

}texte;

// Fonction pour initialiser une structure texte
texte *initialiser_texte(gint w, gint h, gchar lb[200], guint alg, gchar police[30], gint size, gchar styl[15], gchar epaisseur[15], gchar couleur[15], gchar background[15], gchar underline[15]);

// Fonction pour appliquer un style � un �l�ment GTK en fonction d'un type donn�
GtkWidget *style_texte(GtkWidget *element, texte *text, gint type);

/**********************************************************************************************************/

// Structure pour repr�senter une �tiquette avec un texte stylis�
typedef struct Label_et
{
    GtkWidget *widget;    /// Pointeur vers le widget du label
    GtkWidget *pere;      /// Pointeur vers le parent du label
    texte *text;          /// Texte du label
    gboolean selectable;  /// Indique si le texte peut �tre s�lectionn�
    gboolean wrap;        /// Indique si le texte peut �tre coup� en lignes
} Etiquette;

// Fonction pour initialiser une �tiquette (label) avec un texte stylis�
Etiquette *initialiser_label(GtkWidget *parent, texte *stext, gboolean select, gboolean coupe);

void add_label(GtkWidget *pere, texte *text, gboolean selectable, gboolean wrap, gint x, gint y);

#endif // LABEL_H_INCLUDED
