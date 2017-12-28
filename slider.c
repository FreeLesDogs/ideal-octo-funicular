#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "listes_memo.h"
#include "jeu.h"
//#include "editeur.h"
//#include "lire_dossier.h"

int main (int argc, char *argv[])
{
  printf ("Debut slider\n");

  SLIDER S;
  LISTE l = NULL;
  
  //Sinon on joue une partie classique
    partie (S, argv[1],l);

  exit (0);
}
