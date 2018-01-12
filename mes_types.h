#include "graphics.h"

#define TAILLE_CASE 75


typedef struct double_point
{
	POINT p1,p2;
}POINT_D;

typedef struct mur
{
	int *x;
	int *y;
	int *type;
}MUR;

typedef struct slider {
	int L,H;	
	int x,y;	
	POINT balle;
	int sx,sy; 	
	int n; 		
	MUR m;		
}SLIDER;


typedef struct pile{ // Liste chainée pour sauvegarder la position du slider
  POINT balle;
  struct pile *prec;
}*PILE;
