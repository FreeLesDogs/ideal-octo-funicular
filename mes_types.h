#include "graphics.h"
#define TAILLE_CASE 50

struct double_point
{
	POINT p1,p2;
};
typedef struct double_point POINT_D;//c'est suspect toutes les structures

struct mur
{
	int *murx;// mettre x y
	int *mury;
	int *type;
};
typedef struct mur MUR;

struct slider {
	int L,H;	// Largeur et hauteur de la grille
	int x,y;	// Position du slider en nombre de case
	POINT balle;// Position du slider en coordonnées
	int sx,sy; 	// Position sortie POINT_D sortie
	int n; 		// Nombre de murs
	MUR m;		//on utilise la structure mur
};
typedef struct slider SLIDER;


struct element{ // Liste chainée pour sauvegarder la position du slider
  POINT balle;
  struct element *suiv;
};
typedef struct element *LISTE;
