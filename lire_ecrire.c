#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
//faire init apres lire_ecrire
//void erreur argument
SLIDER lire_fichier(FILE * fichier, SLIDER S){
	fscanf (fichier,"%d %d %d %d %d %d ",&S.L,&S.H,&S.x,&S.y,&S.sx,&S.sy);
	return S;
	
}

SLIDER lire_murs (FILE * fichier, SLIDER S){
	int i;
	//fseek();
	fscanf (fichier,"%d",&S.N);
	S.m.murx=malloc(S.N*sizeof(int));
	S.m.mury=malloc(S.N*sizeof(int));
	S.m.type=malloc(S.N*sizeof(int));
	printf ("N= %d \n", S.N);
	for(i=0;i<S.N;i++)
    {
		fscanf(fichier,"%d %d %d",&S.m.murx[i],&S.m.mury[i],&S.m.type[i]);
		printf("mur n°%d:\n abscisse:%d ordonnee:%d type:%d\n",i+1,S.m.murx[i],S.m.mury[i],S.m.type[i]);
	}

	return S;
}

SLIDER init_position_slider(SLIDER S){
	S.ps.x=S.x*TAILLE_CASE+25;
	S.ps.y=S.y*TAILLE_CASE+25;
	return S;
}

SLIDER init_slider (char *nom,SLIDER S){
	
	FILE *fichier = NULL;
	fichier = fopen (nom, "r");
	S = lire_fichier(fichier, S);
	S = init_position_slider(S);
	S = lire_murs (fichier, S);
	fclose (fichier);
	return S;
	
}






void ecrire_fichier (SLIDER S, char *nom)
{
}
