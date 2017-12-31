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
	if(strcmp(argv[1],"-c")==0)
	{
		printf("nom du fichier %s \n",argv[2]);
		ecrire_dans_fic(argv[2]);
		S=init_slider(argv[2],S);
		afficher_slider(S);
		p=bouge(S,p);
		gagnant(S);
	}
	else 
	{
	printf("nom du fichier %s \n",argv[1]);
	S=init_slider(argv[1],S);
	afficher_slider(S);
	p=bouge(S,p);
	gagnant(S);
	}
	
	
	
	//libere_murs (S);
	//clear(p);
	wait_escape();
	exit (0);
}
