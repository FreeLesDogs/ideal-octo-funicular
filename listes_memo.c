#include "mes_types.h"
#include "afficher.h"

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

void libere_murs (SLIDER S)
{

}

PILE touche(PILE p,SLIDER S,int c)//pour revenir en arriere
{
	
	
	if(p!=NULL&&c=='Z')//d'un mouvement
	{
		effacer_le_slider(S);
		p=pop(p);
	}
	if (p!=NULL&&c=='R')//dès le début
	{
		effacer_le_slider(S);
		p=recommencer(p);
	}
	S.balle=p->balle;
	return p;
}

