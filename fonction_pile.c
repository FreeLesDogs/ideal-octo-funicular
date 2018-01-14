#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"

SLIDER re_init(SLIDER S){
	SDL_EnableKeyRepeat(0,0);		//pour éviter de retaper plusieurs fois
	S.x=(S.balle.x-25)/TAILLE_CASE;//pour que le programme sache à tout moment où est la balle
	S.y=(S.balle.y-25)/TAILLE_CASE;
	return S;
}

PILE push(PILE l,SLIDER S)	//Ajoute un deplacement dans la liste
{
	PILE tmp=malloc(sizeof(PILE));
	tmp->balle.x=S.balle.x;
	tmp->balle.y=S.balle.y;
	tmp->prec=l;
	return tmp;
}

PILE pop(PILE l)//Suprime le dernier mouvement
{
	if (l->prec!=NULL)
	{
		l=l->prec;
	}
	return l;
}

PILE recommencer(PILE l)//revient à la premiere pos
{
	while (l->prec!= NULL)
	{
		l=l->prec;
	}
	return l;
}

PILE touche(PILE p,SLIDER S,int c)//pour revenir en arriere ...
{
	
	//effacer_le_slider(S);
	
	if(p!=NULL&&c=='Z')		//...d'un mouvement et ...
	p=pop(p);
	if (p!=NULL&&c=='R')	//...dès le début et ...
	p=recommencer(p);
	
	S.balle=p->balle;		//...on met la nouvelle position dans la pile
	
	return p;
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
	else if(a==EST_CLIC)
	{
		
		if((S.sx*TAILLE_CASE)+5<p.x&&p.x<(S.sx*TAILLE_CASE)+TAILLE_CASE)
		{
			if((S.sy*TAILLE_CASE)+5<p.y&&p.y<(S.sy*TAILLE_CASE)+ TAILLE_CASE)
			printf("sortie");
		}
		
		//quitter(S,p);
	}
    else if(a==EST_TOUCHE)		//en attente de Z ou R
	{
		mouv=touche(mouv,S,c);
		effacer_le_slider(S);
		S.balle=mouv->balle;
		afficher_slider(S);
	}
	
	S=re_init(S);    
}
return mouv;

}

