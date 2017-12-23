#include <stdlib.h>
#include <stdio.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"
#include "listes_memo.h"




LISTE bouge (SLIDER S, LISTE l)
{
	char c;
    int a,f;
	POINT p;
	l=ajout(l,S);
	while (!sortie(S))
    {
		a=wait_key_arrow_clic (&c,&f,&p); //get arrow
		//S.x=(S.balle.x-(TAILLE_CASE/2))/TAILLE_CASE;
		//S.y=(S.balle.y-(TAILLE_CASE/2))/TAILLE_CASE;

	if (a == EST_FLECHE)
	{
		S = deplace (f, S);
		l = ajout(l,S);
	}
	if (a == EST_TOUCHE)
    {
		l = retour (l, S, c);
		S.balle=l->balle;
		afficher_le_slider(S);
	}
	   
    }
  return l;
}
