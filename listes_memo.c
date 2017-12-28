#include "mes_types.h"
#include "afficher.h"

LISTE ajout (LISTE l, SLIDER S)	//Ajoute un deplacement dans la liste
{
  LISTE tmp = malloc (sizeof (struct element));
  tmp->balle.x = S.balle.x;
  tmp->balle.y = S.balle.y;
  tmp->prec=l;
  return tmp;
}

LISTE libere_liste (LISTE l)		//Vide la liste : libere memoire
{
  LISTE ll;
  while (l != NULL)
    {
      ll = l;
      l = l->prec;
      free (ll);
    }
  free (l);
  return NULL;
}

LISTE supp_un_element (LISTE l)	//Suprime le dernier element : pour l'undo
{
  LISTE ll;
  if (l->prec != NULL)
    {
      ll = l;
      l = l->prec;
      free (ll);
    }
  return l;
}

LISTE retour_debut (LISTE l)		//revient à la premiere pos
{
  LISTE ll;
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

LISTE retour (LISTE l, SLIDER S, int c)
{
  effacer_le_slider (S);
  if (l != NULL && c == 'U')	//Pour faire le undo
    {
      l = supp_un_element (l);
    }
  if (l != NULL && l->prec != NULL && c == 'R')	//Pour recommencer
    {
      l = retour_debut (l);
    }
  S.balle = l->balle;
  return l;
}
