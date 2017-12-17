#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

/*void erreurs_arguments(FILE * fichier,SLIDER S){
	fseek(fichier,12,SEEK_SET);
	fscanf(fichier,"%d",S.N);
}*/

SLIDER lire_fichier(FILE * fichier, SLIDER S){
	
	
	fscanf (fichier,"%d %d %d %d %d %d ",&S.L,&S.H,&S.x,&S.y,&S.sx,&S.sy);
	return S;
	
}

SLIDER lire_murs (FILE * fichier, SLIDER S){
	int i;
	//fseek();
	fscanf (fichier,"%d",&S.N);
	S.murx=malloc(S.N*sizeof(int));
	S.mury=malloc(S.N*sizeof(int));
	S.murz=malloc(S.N*sizeof(int));
	printf ("N= %d \n", S.N);
	for(i=0;i<S.N;i++)
    {
		fscanf(fichier,"%d %d %d",&S.murx[i],&S.mury[i],&S.murz[i]);
		printf("%d %d %d\n",S.murx[i],S.mury[i],S.murz[i]);
	}

	return S;
}

SLIDER init_position_sortie(SLIDER S){
	
	S.ps.x=S.x*TAILLE_CASE+25;
	S.ps.y=S.y*TAILLE_CASE+25;
	return S;
	
}

SLIDER init_slider (char *nom,SLIDER S){
	
	FILE *fichier = NULL;
	fichier = fopen (nom, "r");
	S = lire_fichier(fichier, S);
	S = init_position_sortie(S);
	S = lire_murs (fichier, S);
	fclose (fichier);
	return S;
	
}

void ecrire_fichier (SLIDER S, char *nom)
{
}
