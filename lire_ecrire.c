#include "mes_types.h"
#include "afficher.h"
//faire init apres lire_ecrire
//void erreur argument
SLIDER lire_fichier(FILE*fichier,SLIDER S){
	fscanf (fichier,"%d %d %d %d %d %d ",&S.L,&S.H,&S.x,&S.y,&S.sx,&S.sy);
	return S;	
}

SLIDER lire_murs (FILE*fichier,SLIDER S){
	int i;
	//fseek();
	fscanf (fichier,"%d",&S.n);
	S.m.x=malloc(S.n*sizeof(int));
	S.m.y=malloc(S.n*sizeof(int));
	S.m.type=malloc(S.n*sizeof(int));
	for(i=0;i<S.n;i++)
    {
		fscanf(fichier,"%d %d %d",&S.m.x[i],&S.m.y[i],&S.m.type[i]);
	}
	return S;

}

SLIDER init_position_slider(SLIDER S){
	S.balle.x=S.x*TAILLE_CASE+(75/2);
	S.balle.y=S.y*TAILLE_CASE+(75/2);
	return S;
}

SLIDER init_slider(char *fic,SLIDER S){
	
	FILE *fichier;
	fichier=fopen(fic,"r");
	S=lire_fichier(fichier,S);
	S=init_position_slider(S);
	S=lire_murs (fichier, S);
	fclose (fichier);
	return S;
}
void ecrire_dans_fic(char*fic ,int L,int H){
	FILE*fichier;
	fichier=fopen(fic,"w");
	int i,var1,var2,var3,var4;
		
	printf("taille plateau(%d,%d)\n",L,H);
	fprintf(fichier,"%d %d\n",L,H);
	
	printf("position balle en x et y:");
	scanf("%d %d",&var1,&var2);
	printf("position balle(%d,%d)\n",var1,var2);
	fprintf(fichier,"%d %d\n",var1,var2);
	
	printf("position sortie en x et y:");
	scanf("%d %d",&var1,&var2);
	printf("position sortie (%d,%d)\n",var1,var2);
	fprintf(fichier,"%d %d\n",var1,var2);
	
	printf("nombre de murs:");
	scanf("%d",&var1);
	printf("nombre de murs:%d\n",var1);
	fprintf(fichier,"%d\n",var1);
	
	for(i=0;i<var1;i++)
	{
		printf("position mur n°:%d en x et y et type:\n",i+1);
		scanf("%d %d %d",&var2,&var3,&var4);
		printf("position (%d,%d)type mur n°%d:%d \n",i,var2,var3,var4);
		fprintf(fichier,"%d %d %d\n",var2,var3,var4);
	}
	fclose(fichier);
	
}

