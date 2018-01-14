#include <stdlib.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "fonction_pile.h"
#include "deplacements.h"

int main (int argc, char *argv[])
{
	printf ("Debut slider\n");
	SLIDER S;
	PILE p;
	p=NULL;
	if(strcmp(argv[1],"-c")==0)
	{	
		if(argc!=5)
		{
			printf("erreur argument\n");
			exit(1);
		}
		else
		{
			printf("nom du fichier %s \n",argv[4]);
			ecrire_dans_fic(argv[4],atoi(argv[2]),atoi(argv[3]));
			S=init_slider(argv[4],S);
			intro(S);
			afficher_slider(S);
			p=jeu(S,p);
			gagnant(S);
		}
	}
	else if (argc==2)
	{
		if(strcmp(argv[1],"dir_slider")==0)
		{
			printf("dir");
		}
		else
		{		
		printf("nom du fichier %s \n",argv[1]);
		S=init_slider(argv[1],S);
		intro(S);
		afficher_slider(S);
		p=jeu(S,p);
		gagnant(S);
		}
	}
	
	wait_escape();
	exit (0);
}
