#include "mes_types.h"
#include "listes_memo.h"
#include "afficher.h"

SLIDER re_init(SLIDER S){
	//pour que l'on sache à tout moment où est la balle
	S.x=(S.balle.x-25)/TAILLE_CASE;
	S.y=(S.balle.y-25)/TAILLE_CASE;
	return S;
}
/*void droite(SLIDER S)
{
	int u,i;
	//int tab[S.n];
	if(S.x==S.L+1)u=0; 
	for(i=0;i<S.n;i++)
	{
		if(S.m.y[i]==S.y&&S.m.type[i]==3)
		u=S.m.y[i]-S.y;
		printf("%d",u);
		
	}
	
}*/
SLIDER deplace_droite(SLIDER S)
{
	int a, tmp, i;
	a=tmp=S.L+1;
	for (i=0;i<S.n; i++)
    {
		if (S.m.y[i]==S.y)
			{
				if(S.m.x[i]==S.x&&S.m.type[i]==3)
				return S;
				else if (S.m.x[i]>S.x)
				{
					if(S.m.type[i]==9)
					tmp=S.m.x[i]-1;
					else if(S.m.type[i]==3)
					tmp=S.m.x[i];
				}
			}
		if (tmp<a)
		a=tmp;
	}
    if (a==S.L+1)
	a=S.L-1;
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
		if(S.y==S.m.y[i])
			{
				if(S.x==S.m.x[i]&&S.m.type[i]==9)
				return S;
				else if(S.x>S.m.x[i])
				{
					if(S.m.type[i]==9)
					tmp=S.m.x[i];
					else if(S.m.type[i]==3)
					tmp=S.m.x[i]+1;
				}
			}
		if (tmp > a)
		a=tmp;
    }
	if(a==-1)
    a=0;
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
  a=tmp=-1;
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
  if (a ==-1)
    a = 0;
  if (S.y>S.sy&& a < S.sy && S.x == S.sx)
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

PILE bouge (SLIDER S,PILE mouv)
{
	char c;
	int a,f;
	POINT p;
	mouv=push(mouv,S);//insertion position initiale
	SDL_EnableKeyRepeat (0,0);
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
		mouv=touche(mouv,S,c);
		S.balle=mouv->balle;
		afficher_slider(S);
	}
      
}
return mouv;

}
