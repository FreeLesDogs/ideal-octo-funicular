#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"
#include "listes_memo.h"

/*
PILE bouge (SLIDER S,PILE l)
{
	char c;
	int a,f;
	POINT p;
	l=push(l,S);//insertion position initiale
	S=re_init(S);
while (!sortie (S))
{
	a=wait_key_arrow_clic (&c,&f,&p);
	
	if (a==EST_FLECHE)
	{
		S=deplace(f,S);
		l=push(l,S);
	}
    if (a==EST_TOUCHE)
	{
		l =retour (l, S, c);
		S.balle = l->balle;
		afficher_le_slider(S);
	}
      
}
return l;

}
*/

