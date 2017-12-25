#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "jeu.h"
#include "afficher.h"
/*Test sur toute la ligne si il y a un mur vertical, s'il y en a un prend la valeur de la case à gauche, puis compare
 laquelle est plus pres du Slider*/
SLIDER deplace_droite(SLIDER S)
{
	int a, tmp, i;//supprimer tmp
  a = tmp = S.L + 1;
  for (i=0;i<S.n; i++)
    {
		if (S.m.mury[i] == S.y && S.m.murx[i] == S.x && S.m.type[i] == 3)
			return S;
		if (S.m.mury[i] == S.y && S.m.murx[i] > S.x && S.m.type[i] == 9)
			tmp = S.m.murx[i] - 1;
		if (S.m.mury[i] == S.y && S.m.murx[i] > S.x && S.m.type[i] == 3)
			tmp = S.m.murx[i];
		if (tmp < a)
			a = tmp;
		if (a == S.L + 1)
			a = S.L - 1;
    }
	if (S.x<S.sx && a > S.sx && S.y == S.sy)
    {
		a = S.sx;
    }
	S.x=a;
    a=a*TAILLE_CASE+25;
	for (i=S.balle.x;i<a;i+=TAILLE_CASE)
    {
		effacer_le_slider (S);
		S.balle.x+=TAILLE_CASE;
		afficher_le_slider (S);
    }

	return S;
}

SLIDER deplace_gauche (SLIDER S)
{
	int a,tmp,i;
	a=tmp=-1;//trouver une autre facon de savoir quelle mur est le plus proche
	for(i=0;i<S.n;i++) 
    {
		if(S.y==S.m.mury[i]&&S.x==S.m.murx[i]&&S.m.type[i]==9)
		return S;
		if(S.y==S.m.mury[i]&&S.x>S.m.murx[i]&&S.m.type[i]==9)
		tmp=S.m.murx[i];
		if(S.y==S.m.mury[i]&&S.x>S.m.murx[i]&&S.m.type[i]==3)
		tmp=S.m.murx[i] + 1;
		if (tmp > a)
		a=tmp;
    }
  if (a == -1)
    a = 0;
	if (S.x>S.sx && a<S.sx && S.y == S.sy)
    {
		a = S.sx;
    }
	S.x = a;
	a = a * TAILLE_CASE + (TAILLE_CASE / 2);
	for (i = S.balle.x; i > a; i -= TAILLE_CASE)
    {
		effacer_le_slider (S);
		S.balle.x -= TAILLE_CASE;
		afficher_le_slider (S);
    }
  return S;
}

SLIDER deplace_haut (SLIDER S)
{
  int a, tmp, i;
  a = tmp = S.H + 1;
  for (i=0;i<S.n;i++)
    {
      if (S.m.mury[i] == S.y && S.m.murx[i] == S.x && S.m.type[i] == 0)
	return S;
      if (S.m.murx[i] == S.x && S.m.mury[i] > S.y && S.m.type[i] == 0)
	tmp = S.m.mury[i];
      if (S.m.murx[i] == S.x && S.m.mury[i] > S.y && S.m.type[i] == 6)
	tmp = S.m.mury[i] - 1;
      if (tmp < a)
	a = tmp;
    }
  if (a == S.H + 1)
    a = S.H - 1;

  if (S.y<S.sy && a > S.sy && S.x == S.sx)
    {
      a = S.sy;
    }
  S.y = a;
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.balle.y; i < a; i += TAILLE_CASE)
    {
      effacer_le_slider (S);
      S.balle.y += TAILLE_CASE;
      afficher_le_slider (S);
    }

  return S;
}

SLIDER deplace_bas (SLIDER S)
{
  int a, tmp,i;
  a = tmp = -2;
  for (i=0;i<S.n;i++)
    {
      if (S.m.mury[i] == S.y && S.m.murx[i] == S.x && S.m.type[i] == 6)
	return S;
      if (S.m.murx[i] == S.x && S.m.mury[i] < S.y && S.m.type[i] == 0)
	tmp = S.m.mury[i] + 1;
      if (S.m.murx[i] == S.x && S.m.mury[i] < S.y && S.m.type[i] == 6)
	tmp = S.m.mury[i];
      if (tmp > a)
	a = tmp;
    }
  if (a == -2)
    a = 0;
  if (S.y>S.sy && a < S.sy && S.x == S.sx)
    {
      a = S.sy;
    }
    S.y = a;
  a = a * TAILLE_CASE + (TAILLE_CASE / 2);
  for (i = S.balle.y; i > a; i -= TAILLE_CASE)
    {
      effacer_le_slider (S);
      S.balle.y -= TAILLE_CASE;
      afficher_le_slider (S);
    }
  return S;
}

SLIDER deplace (int f,SLIDER S)
{
	if(f == FLECHE_GAUCHE)
    S=deplace_gauche(S);// mettre get_arrow dans les deplace______________
	if(f == FLECHE_DROITE)
    S=deplace_droite (S);
	if(f == FLECHE_HAUTE)
    S = deplace_haut (S);
	if (f == FLECHE_BAS)
    S = deplace_bas (S);
    
	return S;
}

int sortie(SLIDER S)
{
	while(S.x==S.sx && S.y==S.sy)
	{
		return 1;
	}
	return 0;
}
