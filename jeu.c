#include <stdlib.h>
#include <stdio.h>
#include "mes_types.h"
#include "afficher.h"
#include "deplacements.h"
#include "listes_memo.h"
#include "lire_ecrire.h"

LISTE bouge (SLIDER S, LISTE l)	//Gere le mouvement du Slider
{
  char c;
  int a, f;
  POINT p;
  l = ajout (l, S);
  while (!sortie (S))
    {
      a = wait_key_arrow_clic (&c, &f, &p);
      SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
      S.x = (S.balle.x - 25) / TAILLE_CASE;
      S.y = (S.balle.y - 25) / TAILLE_CASE;

      if (a == EST_FLECHE)
	{
	  S = deplace (f, S);
	  l = ajout (l, S);
	}
      if (a == EST_TOUCHE)
	{
	  l = retour (l, S, c);
	  S.balle = l->balle;
	  afficher_le_slider (S);

	}
      
    }
  return l;
}

void partie (SLIDER S, char *nom, LISTE l)
{
  printf ("nom du fichier %s \n", nom);
  S = init_slider (nom,S);
  afficher_slider (S);
  l = bouge (S, l);
  gagnant (S);
  libere_murs (S);
  libere_liste (l);
  wait_escape ();
}
