#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "jeu.h"
#include "afficher.h"
/*Test sur toute la ligne si il y a un mur vertical, s'il y en a un prend la valeur de la case à gauche, puis compare
 laquelle est plus pres du Slider*/

int mur_verticalG (SLIDER S)	// Retourne la postion à gauche du mur le plus proche à gauche du slider
{
	int a,tmp,i;
	a=tmp=-1;//trouver une autre facon de savoir quelle mur est le plus proche
	for(i=0;i<S.n;i++) 
    {
		if(S.y==S.m.mury[i]&&S.x==S.m.murx[i]&&S.m.type[i]==9)
		return S.x;
		if(S.y==S.m.mury[i]&&S.x>S.m.murx[i]&&S.m.type[i]==9)
		tmp=S.m.murx[i];
		if(S.y==S.m.mury[i]&&S.x>S.m.murx[i]&&S.m.type[i]==3)
		tmp=S.m.murx[i] + 1;
		if (tmp > a)
		a=tmp;
    }
  if (a == -1)
    a = 0;
  return a;
}

int mur_verticalD (SLIDER S) // Retourne la postion à droite du mur le plus proche à droite du slider 
//ptet a combiner avec deplace
{
  int a, tmp, i;
  a = tmp = S.L + 1;
  for (i = 0; i < S.n; i++)
    {
      if (S.m.mury[i] == S.y && S.m.murx[i] == S.x && S.m.type[i] == 3)
	return S.x;
      if (S.m.mury[i] == S.y && S.m.murx[i] > S.x && S.m.type[i] == 9)
	tmp = S.m.murx[i] - 1;
      if (S.m.mury[i] == S.y && S.m.murx[i] > S.x && S.m.type[i] == 3)
	tmp = S.m.murx[i];
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
  for (n = 0; n < S.n; n++)
    {
      if (S.m.mury[n] == S.y && S.m.murx[n] == S.x && S.m.type[n] == 0)
	return S.y;
      if (S.m.murx[n] == S.x && S.m.mury[n] > S.y && S.m.type[n] == 0)
	tmp = S.m.mury[n];
      if (S.m.murx[n] == S.x && S.m.mury[n] > S.y && S.m.type[n] == 6)
	tmp = S.m.mury[n] - 1;
      if (tmp < a)
	a = tmp;
    }
  if (a == S.H + 1)
    a = S.H - 1;

  return a;
}

int mur_horizontalB (SLIDER S) 	// retourne la position du slider en dessous du mur le plus proche de lui
{
  int a, tmp, n;
  a = tmp = -2;
  for (n = 0; n < S.n; n++)
    {
      if (S.m.mury[n] == S.y && S.m.murx[n] == S.x && S.m.type[n] == 6)
	return S.y;
      if (S.m.murx[n] == S.x && S.m.mury[n] < S.y && S.m.type[n] == 0)
	tmp = S.m.mury[n] + 1;
      if (S.m.murx[n] == S.x && S.m.mury[n] < S.y && S.m.type[n] == 6)
	tmp = S.m.mury[n];
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
    a=a*TAILLE_CASE+25;
	for (i = S.balle.x; i < a; i += TAILLE_CASE)
    {
		
		effacer_le_slider (S);
		S.balle.x += TAILLE_CASE;
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
  int a, i;
  a = mur_horizontalH (S);
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
  int a, i;
  a = mur_horizontalB (S);
  if (S.y>S.sy && a < S.sy && S.x == S.sx)//utiliser pos_mur_g
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
int pos_mur_g(SLIDER S)
{
	int i,j,k;int tab[S.n];
	j=0;
	for(i=0;i<S.n;i++)
	{
		if((S.m.type[i]==9||S.m.type[i]==3)&&(S.m.mury[i]==S.y)&&(S.m.murx[i]<S.x))	//attention au 9 3
		{
			tab[j]=S.m.murx[i];
			printf("%d \n",tab[j]);
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		k=0;
		if(tab[i]>=k)
		{
			k=tab[i];
		}
	}
	printf(" %d\n",k);
return k;
}
void position(SLIDER S)
{
	int a;
	a=pos_mur_g(S);
}
int sortie(SLIDER S)
{
	if(S.x==S.sx && S.y==S.sy)return 1;
	else return 0;
}
