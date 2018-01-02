#include "mes_types.h"
#include "listes_memo.h"
#include "afficher.h"

SLIDER re_init(SLIDER S){
	SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
	S.x=(S.balle.x-25)/TAILLE_CASE;
	S.y=(S.balle.y-25)/TAILLE_CASE;
	return S;
}

SLIDER deplace_droite(SLIDER S)
{
	int a, tmp, i;//supprimer tmp
	a=tmp=S.L+1;
	for (i=0;i<S.n; i++)
    {
		if (S.m.y[i] == S.y && S.m.x[i] == S.x && S.m.type[i] == 3)
			return S;
		if (S.m.y[i]==S.y&& S.m.x[i]> S.x && S.m.type[i] == 9)
			tmp=S.m.x[i]-1;
		if (S.m.y[i] == S.y && S.m.x[i] > S.x && S.m.type[i] == 3)
			tmp=S.m.x[i];
		if (tmp<a)
			a=tmp;
		if (a==S.L+1)
			a=S.L-1;
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
	a=tmp=-1;
	for(i=0;i<S.n;i++) 
    {
		if(S.y==S.m.y[i]&&S.x==S.m.x[i]&&S.m.type[i]==9)
		return S;
		if(S.y==S.m.y[i]&&S.x>S.m.x[i]&&S.m.type[i]==9)
		tmp=S.m.x[i];
		if(S.y==S.m.y[i]&&S.x>S.m.x[i]&&S.m.type[i]==3)
		tmp=S.m.x[i] + 1;
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
	if (S.m.y[i] == S.y && S.m.x[i] == S.x && S.m.type[i] == 0)
		return S;
	if (S.m.x[i] == S.x && S.m.y[i] > S.y && S.m.type[i] == 0)
		tmp = S.m.y[i];
    if (S.m.x[i] == S.x && S.m.y[i] > S.y && S.m.type[i] == 6)
		tmp = S.m.y[i] - 1;
	if (tmp < a)
		a = tmp;
    }
	if (a == S.H + 1)
		a = S.H - 1;

	if(S.y<S.sy && a > S.sy && S.x == S.sx)
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
  a=tmp=-2;
  for (i=0;i<S.n;i++)
    {
      if (S.m.y[i] == S.y && S.m.x[i] == S.x && S.m.type[i] == 6)
	return S;
      if (S.m.x[i] == S.x && S.m.y[i] < S.y && S.m.type[i] == 0)
	tmp = S.m.y[i]+1;
      if (S.m.x[i] == S.x && S.m.y[i] < S.y && S.m.type[i] == 6)
	tmp = S.m.y[i];
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
    S=deplace_gauche(S);
	if(f == FLECHE_DROITE)
    S=deplace_droite (S);
	if(f == FLECHE_HAUTE)
    S = deplace_haut (S);
	if (f == FLECHE_BAS)
    S = deplace_bas (S);
    S=re_init(S);
	return S;
}

PILE bouge (SLIDER S,PILE mouv)//void
{
	char c;
	int a,f;
	POINT p;
	mouv=push(mouv,S);//insertion position initiale
	S=re_init(S);
while (!(S.x==S.sx&&S.y==S.sy))
{
	a=wait_key_arrow_clic (&c,&f,&p);
	
	if (a==EST_FLECHE)
	{
		S=deplace(f,S);
		mouv=push(mouv,S);
	}
    if (a==EST_TOUCHE)
	{
		mouv=retour (mouv, S, c);
		S.balle=mouv->balle;
		afficher_slider(S);
	}
      
}
return mouv;

}
