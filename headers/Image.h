#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <gtk/gtk.h>

// Structure pour représenter une image avec différentes options
typedef struct
{
    GtkWidget *widget;            // Widget représentant l'image// Widget parent de l'image
    gint type;                    // Type d'image (1:fichier, 2:animation, 3:stock)
    const gchar *icon_anim_stock; // Chemin du fichier, nom de l'animation, ou nom d'icône selon le type
    GdkPixbufAnimation *anim;     // Animation de l'image (utilisé si le type est 2)
    GtkIconSize size;             // Taille de l'icône (utilisé si le type est 3)
    gint h;
    gint w;
    GtkWidget *parent;
} image;

// Fonction pour initialiser une image avec des paramètres spécifiques
image *initialiser_image(GtkWidget *pere, gint t, const gchar *fichier, GtkIconSize sz, gint w, gint h);

// Fonction pour changer la taille de l'image en fonction des spécifications
void change_size(image *img);

// Fonction pour créer l'image en fonction du type spécifié
void creer_img(image *img);

void add_image(GtkWidget *pere, gint type, const gchar* fichier, GtkIconSize size_icon, gint w, gint h, gint x, gint y);

#endif // IMAGE_H_INCLUDED
