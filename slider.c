#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "listes_memo.h"
#include "deplacements.h"

int main (int argc, char *argv[])
{
	printf ("Debut slider\n");

	SLIDER S;
	PILE p;
	p=NULL;
	ecrire_dans_fic(argv[1]);
	printf("nom du fichier %s \n",argv[1]);
	S=init_slider(argv[1],S);
	afficher_slider(S);
	
	p=bouge(S,p);
	gagnant(S);
	
	
	//libere_murs (S);
	//libere_liste(p);
	wait_escape();
	exit (0);
}
