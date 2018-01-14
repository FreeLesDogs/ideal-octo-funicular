#include "mes_types.h"
#include "listes_memo.h"
#include "afficher.h"

SLIDER re_init(SLIDER S){
	SDL_EnableKeyRepeat(0,0);		//pour éviter de retaper plusieurs fois
	S.x=(S.balle.x-25)/TAILLE_CASE;//pour que le programme sache à tout moment où est la balle
	S.y=(S.balle.y-25)/TAILLE_CASE;
	return S;
}

SLIDER deplace_droite(SLIDER S)
{
	int a, tmp, i;
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
	{
		a=S.sx;
	}
	printf("%d\n",a);
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
    {
		a=S.sx;
	}
	printf("%d\n",a);
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
    {
		a=S.sy;
	}
	printf("%d\n",a);
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
    {
		a=S.sy;
	}
	S.y=a;
	effacer_le_slider(S);
	S.balle.y=S.y*TAILLE_CASE+(75/2);
	afficher_le_slider(S);
	return S;
}

PILE jeu(SLIDER S,PILE mouv)
{
	char c;
	int a,f;
	POINT p;
	mouv=push(mouv,S);		//insertion position initiale
	S=re_init(S);
while (!(S.x==S.sx&&S.y==S.sy))//tant que la balle n'est pas sur la sortie
{
	
	a=wait_key_arrow_clic (&c,&f,&p);
	
	if(a==EST_FLECHE)			//en attente de fleches
	{
		if(f==FLECHE_BAS)
		S=deplace_bas(S);
		else if(f==FLECHE_DROITE)
		S=deplace_droite(S);
		else if(f==FLECHE_GAUCHE)
		S=deplace_gauche(S);
		else if(f==FLECHE_HAUTE)
		S=deplace_haut(S);
	
		mouv=push(mouv,S);		//insertion nouvelle position
	}
    else if(a==EST_TOUCHE)		//en attente de Z ou R
	{
		mouv=touche(mouv,S,c);
		effacer_le_slider(S);
		S.balle=mouv->balle;
		afficher_slider(S);
	}
	else if(a==EST_CLIC)
	{
		
	}
	  S=re_init(S);    
}
return mouv;

}
