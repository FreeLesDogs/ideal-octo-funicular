#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "jeu.h"
#include "afficher.h"
/*Test sur toute la ligne si il y a un mur vertical, s'il y en a un prend la valeur de la case à gauche, puis compare
 * laquelle est plus pres du Slider*/
int
mur_verticalG (SLIDER S)	// Retourne la postion à gauche du mur le plus proche à gauche du slider
{
  int a, tmp, i;
  a = tmp = -1;
  for (i=0;i<S.N;i++) 
    {
      if (S.mury[i]==S.y&&S.murx[i]==S.x&&S.murz[i]==9)
	return S.x;
      if (S.mury[i]==S.y&&S.murx[i]<S.x&&S.murz[i]==9)
	tmp=S.murx[i];
      if(S.mury[i]==S.y && S.murx[i]<S.x&&S.murz[i]==3)
	tmp = S.murx[i] + 1;
      if (tmp > a)
	a=tmp;
    }
  if (a == -1)
    a = 0;
  return a;
}

int
mur_verticalD (SLIDER S) // Retourne la postion à droite du mur le plus proche à droite du slider
{
  int a, tmp, n;
  a = tmp = S.L + 1;
  for (n = 0; n < S.N; n++)
    {
      if (S.mury[n] == S.y && S.murx[n] == S.x && S.murz[n] == 3)
	return S.x;
      if (S.mury[n] == S.y && S.murx[n] > S.x && S.murz[n] == 9)
	tmp = S.murx[n] - 1;
      if (S.mury[n] == S.y && S.murx[n] > S.x && S.murz[n] == 3)
	tmp = S.murx[n];
      if (tmp < a)
	a = tmp;
      if (a == S.L + 1)
	a = S.L - 1;
    }
  return a;
}

int
mur_horizontalH (SLIDER S)	// retourne la position du slider au dessus du mur le plus proche de lui
{
  int a, tmp, n;
  a = tmp = S.H + 1;
  for (n = 0; n < S.N; n++)
    {
      if (S.mury[n] == S.y && S.murx[n] == S.x && S.murz[n] == 0)
	return S.y;
      if (S.murx[n] == S.x && S.mury[n] > S.y && S.murz[n] == 0)
	tmp = S.mury[n];
      if (S.murx[n] == S.x && S.mury[n] > S.y && S.murz[n] == 6)
	tmp = S.mury[n] + 1;
      if (tmp > a)
	a = tmp;
    }
  if (a == S.H + 1)
    a = S.H - 1;//bloque max à remplacer avec choc
  return a;
}

int
mur_horizontalB (SLIDER S) 	// retourne la position du slider en dessous du mur le plus proche de lui
{
  int a, tmp, n;
  a = tmp = -2;
  for (n = 0; n < S.N; n++)
    {
      if (S.mury[n] == S.y && S.murx[n] == S.x && S.murz[n] == 6)
	return S.y;
      if (S.murx[n] == S.x && S.mury[n] < S.y && S.murz[n] == 0)
	tmp = S.mury[n] + 1;
      if (S.murx[n] == S.x && S.mury[n] < S.y && S.murz[n] == 6)
	tmp = S.mury[n];
      if (tmp > a)
	a = tmp;
    }
  if (a == -2)
    a = 0;
  return a;
}

SLIDER deplace_droite(SLIDER S)
{
  int a,i;
  a=mur_verticalD(S);
  
  if (S.x<S.sx && a > S.sx && S.y == S.sy)
    {
      a = S.sx;
    }
   S.x = a;
    printf("a= %d",a);
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.ps.x; i < a; i += TAILLE_CASE)
    {
      attendre (10);
      effacer_le_slider (S);
      S.ps.x += TAILLE_CASE;
      afficher_le_slider (S);
    }

  return S;
}

SLIDER deplace_gauche (SLIDER S)
{
  int a, i;
  a = mur_verticalG (S);
  if (S.x>S.sx && a<S.sx && S.y == S.sy)
    {
      a = S.sx;
    }
   S.x = a;
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.ps.x; i > a; i -= TAILLE_CASE)
    {
      attendre (10);
      effacer_le_slider (S);
      S.ps.x -= TAILLE_CASE;
      afficher_le_slider (S);
    }
  return S;
}

SLIDER deplace_haut (SLIDER S)
{
  int a, i;
  a = mur_horizontalH (S);
  if (S.y<S.sy && a > S.sy && S.x == S.sx)
    {
      a = S.sy;
    }
  S.y = a;
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.ps.y; i < a; i += TAILLE_CASE)
    {
      attendre (10);
      effacer_le_slider (S);
      S.ps.y += TAILLE_CASE;
      afficher_le_slider (S);
    }

  return S;
}

SLIDER deplace_bas (SLIDER S)
{
  int a, i;
  a = mur_horizontalB (S);
  if (S.y>S.sy && a < S.sy && S.x == S.sx)
    {
      a = S.sy;
    }
    S.y = a;
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.ps.y; i > a; i -= TAILLE_CASE)
    {
      attendre (10);
      effacer_le_slider (S);
      S.ps.y -= TAILLE_CASE;
      afficher_le_slider (S);
    }
  return S;
}

SLIDER deplace (int f,SLIDER S)
{
  if (f == FLECHE_GAUCHE)
    S = deplace_gauche(S);// mettre get_arrow dans les deplace______________
  if (f == FLECHE_DROITE)
    S = deplace_droite (S);
  if (f == FLECHE_HAUTE)
    S = deplace_haut (S);
  if (f == FLECHE_BAS)
    S = deplace_bas (S);
  return S;
}
