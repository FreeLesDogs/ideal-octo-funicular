#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"

SLIDER re_init(SLIDER S){
	SDL_EnableKeyRepeat(0,0);			//pour éviter de retaper plusieurs fois
	S.x=(S.balle.x-25)/TAILLE_CASE;		//pour que le programme sache à tout moment où est la balle
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
	l=l->prec;
	
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

PILE jeu(SLIDER S,PILE mouv)
{
	char c;	int a,f;	POINT p;
	mouv=push(mouv,S);		//insertion position initiale
	S=re_init(S);
while (!(S.x==S.sx&&S.y==S.sy))//tant que la balle n'est pas sur la sortie
{
	
	a=wait_key_arrow_clic (&c,&f,&p);
	
	if(a==EST_FLECHE)			//En attente de fleches...
	{
		if(f==FLECHE_BAS)
		S=deplace_bas(S);
		else if(f==FLECHE_DROITE)
		S=deplace_droite(S);
		else if(f==FLECHE_GAUCHE)
		S=deplace_gauche(S);
		else if(f==FLECHE_HAUTE)
		S=deplace_haut(S);
	
		mouv=push(mouv,S);		//... pour inserer nouvelle position
	}
    else if(a==EST_TOUCHE)						//En attente de Z ou R pour revenir en arriere...
	{
		if(mouv!=NULL&&mouv->prec!=NULL)		//...d'un mouvement et ...
		{
			if(c=='Z')							//...d'un mouvement et ...
			mouv=pop(mouv);
			if (c=='R')							//...dès le début et ...
			mouv=recommencer(mouv);
	
			effacer_le_slider(S);
			S.balle=mouv->balle;				//...on met la nouvelle position dans la pile
			afficher_slider(S);
		}
	}
	
	S=re_init(S);    
}
return mouv;

}

