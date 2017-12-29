#include "mes_types.h"
#include "afficher.h"

PILE push(PILE l, SLIDER S)	//Ajoute un deplacement dans la liste
{
  PILE tmp = malloc (sizeof (PILE));
  tmp->balle.x = S.balle.x;
  tmp->balle.y = S.balle.y;
  tmp->prec=l;
  return tmp;
}

PILE libere_liste (PILE l)		//Vide la liste : libere memoire
{
  PILE ll;
  while (l != NULL)
    {
      ll = l;
      l = l->prec;
      free (ll);
    }
  free (l);
  return NULL;
}

PILE pop(PILE l)	//Suprime le dernier element : pour l'undo
{
  PILE ll;
  if (l->prec != NULL)
    {
      ll = l;
      l = l->prec;
      free (ll);
    }
  return l;
}

PILE retour_debut (PILE l)		//revient à la premiere pos
{
  PILE ll;
  while (l->prec!= NULL)
    {
      ll = l;
      l = l->prec;
      free (ll);
    }
  return l;
}

void libere_murs (SLIDER S)
{

}

PILE retour (PILE l, SLIDER S, int c)
{
  
  if (l != NULL && c == 'U')	//Pour faire le undo
    {
	effacer_le_slider(S);
	l=pop(l);
    }
  if (l != NULL && c == 'R')	//Pour recommencer
    {
		effacer_le_slider (S);
		l = retour_debut (l);
    }
  S.balle = l->balle;
  return l;
}
