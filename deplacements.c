#include "mes_types.h"
#include "afficher.h"

SLIDER deplace_droite(SLIDER S)
{
	int a,tmp,i;
	a=tmp=S.L-1;
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
	if(S.x<S.sx&&a>S.sx&&S.y==S.sy)
	a=S.sx;
	
	S.x=a;
	effacer_le_slider(S);
	S.balle.x=S.x*TAILLE_CASE+(75/2);
	afficher_le_slider(S);
	
	return S;
}

SLIDER deplace_gauche (SLIDER S)
{
	int a,tmp,i;
	a=tmp=0;
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
		if (tmp>a)
		a=tmp;
    }
    if(S.x>S.sx&&a<S.sx&&S.y==S.sy)//pour que l'on s'arrete à la sortie si elle est entre la balle et un mur
    a=S.sx;
	
	S.x=a;
	effacer_le_slider(S);
	S.balle.x=S.x*TAILLE_CASE+(75/2);
	afficher_le_slider(S);
	
	return S;
}

SLIDER deplace_haut(SLIDER S)
{
	int a, tmp, i;
	a=tmp=S.H-1;
	for (i=0;i<S.n;i++)
    {
		if(S.m.x[i]==S.x)
		{
			if (S.m.y[i]==S.y && S.m.type[i]==0)
			return S;
			else if(S.m.y[i]>S.y)
			{
				if(S.m.type[i]==0)
				tmp=S.m.y[i];
				else if(S.m.type[i]==6)
				tmp=S.m.y[i]-1;
			}
		}
		if (tmp < a)
		a = tmp;
    }
    if(S.y<S.sy&&a>S.sy&&S.x==S.sx)
    a=S.sy;
	
	S.y=a;
	effacer_le_slider(S);
	S.balle.y=S.y*TAILLE_CASE+(75/2);
	afficher_le_slider(S);

	return S;
}

SLIDER deplace_bas (SLIDER S)
{
	int a, tmp,i;
	a=tmp=0;
	for (i=0;i<S.n;i++)
	{
		if(S.m.x[i]==S.x)
		{
			if(S.m.y[i]==S.y&&S.m.type[i]==6)
			return S;
			else if(S.m.y[i]<S.y)
			{
				if(S.m.type[i]==0)
				tmp=S.m.y[i]+1;
				else if(S.m.type[i]==6)
				tmp = S.m.y[i];				
			}
		}
	if(tmp>a)
	a=tmp;
    }
    if(S.y>S.sy&&a<S.sy&&S.x==S.sx)
    a=S.sy;
	
	S.y=a;
	effacer_le_slider(S);
	S.balle.y=S.y*TAILLE_CASE+(75/2);
	afficher_le_slider(S);
	return S;
}
