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
void ecrire_dans_fic(char*fic){
	FILE*fichier;
	fichier=fopen(fic,"w");
	int i;
	int largeur;
	int hauteur;
	
	int pos_balle_x;
	int pos_balle_y;
	
	int pos_sortie_x;
	int pos_sortie_y;
	
	int nb_murs;
	int pos_murs_x;
	int pos_murs_y;
	int types_murs;
	
	printf("largeur et hauteur:");
	scanf("%d %d",&largeur,&hauteur);
	printf("largeur:%d hauteur:%d\n",largeur,hauteur);
	fprintf(fichier,"%d %d\n",largeur,hauteur);
	
	printf("position balle en x et y:");
	scanf("%d %d",&pos_balle_x,&pos_balle_y);
	printf("position balle:%d %d\n",pos_balle_x,pos_balle_y);
	fprintf(fichier,"%d %d\n",pos_balle_x,pos_balle_y);
	
	printf("position sortie en x et y:");
	scanf("%d %d",&pos_sortie_x,&pos_sortie_y);
	printf("position sortie:%d %d\n",pos_sortie_x,pos_sortie_y);
	fprintf(fichier,"%d %d\n",pos_sortie_x,pos_sortie_y);
	
	printf("nombre de murs:");
	scanf("%d",&nb_murs);
	printf("nombre de murs:%d\n",nb_murs);
	fprintf(fichier,"%d\n",nb_murs);
	
	for(i=0;i<nb_murs;i++)
	{
		printf("position mur n°:%d en x et y et type:",i+1);
		scanf("%d %d %d",&pos_murs_x,&pos_murs_y,&types_murs);
		printf("pos x y types murs %d %d %d ",pos_murs_x,pos_murs_y,types_murs);
		fprintf(fichier,"%d %d %d\n",pos_murs_x,pos_murs_y,types_murs);
	}
	fclose(fichier);
	
}
