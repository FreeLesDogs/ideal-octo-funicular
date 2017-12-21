#include <stdlib.h>
#include <stdio.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"
#include "listes_memo.h"
int sortie(SLIDER S)
{
	S.sx = S.sx * TAILLE_CASE + (TAILLE_CASE / 2);
    S.sy = S.sy * TAILLE_CASE + (TAILLE_CASE / 2);
	if (S.ps.x ==S.sx && S.ps.y ==S.sy) return 1;
	return 0;
}


LISTE
bouge (SLIDER S, LISTE l)
{
  char c;
  int a,f;
  POINT p;
  l=ajout(l,S);
  while (!sortie(S))
    {
      a = wait_key_arrow_clic (&c,&f,&p);
      S.x=(S.ps.x-(TAILLE_CASE/2)) /TAILLE_CASE;
      S.y=(S.ps.y-(TAILLE_CASE/2)) /TAILLE_CASE;

      if (a == EST_FLECHE)
	{
	  S = deplace (f, S);
	  l = ajout(l,S);
	}
      if (a == EST_TOUCHE)
      {
		   l = retour (l, S, c);
		   S.ps=l->ps;
		   afficher_le_slider(S);
		   
	   }
	   S.coups++;
    }
  return l;
}
