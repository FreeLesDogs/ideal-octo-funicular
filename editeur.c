#include <stdlib.h>
#include <stdio.h>
#include "mes_types.h"
#include "afficher.h"


SLIDER ecrire_taille_init(FILE * f,int L,int H,SLIDER S)
{
	fprintf(f,"%d %d \n",L,H);
	S.L=L; S.H=H;
	initialiser_affichage(S);
	afficher_quadrillage(S);
	return S;
}
SLIDER ecrire_position_sortie(FILE * f,SLIDER S)
{
	int a,fl; char c; POINT p;
	a=0;
	while(a!= EST_CLIC){
	a = wait_key_arrow_clic (&c, &fl, &p);
    SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
	}
	S.sx=p.x/TAILLE_CASE;
	S.sy=p.y/TAILLE_CASE;
	afficher_sortie(S);
	fprintf(f,"%d %d \n",S.sx,S.sy);
	
	return S;
}

SLIDER ecrire_position_slider(FILE * f,SLIDER S)
{
	int a,fl; char c; POINT p;
	a=0;
	while(a!= EST_CLIC){
	a = wait_key_arrow_clic (&c, &fl, &p);
    SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
	}
	S.x=p.x/TAILLE_CASE;
	S.y=p.y/TAILLE_CASE;
	S.balle.x=((S.x)*TAILLE_CASE)+(TAILLE_CASE/2); S.balle.y=((S.y)*TAILLE_CASE)+(TAILLE_CASE/2);
	afficher_le_slider(S);
	fprintf(f,"%d %d \n",S.x,S.y);
	return S;
}

SLIDER ecrire_nb_murs(FILE * f,SLIDER S) //demande nombre de murs
{
	int a,fl,n,i; char c; POINT p;
	a=n=i=0;
	printf("indiquez le nombre de murs souhaité apuyer sur fleche haute ou fleche bas pour varier de 1, puis valider sur une touche");
	while(a!=EST_TOUCHE){
		a=wait_key_arrow_clic (&c, &fl, &p);
		SDL_EnableKeyRepeat (0, SDL_DEFAULT_REPEAT_INTERVAL);
		if (fl==FLECHE_HAUTE)
		{ 
			i++;
			printf("i= %d",i);
		}
		if(fl==FLECHE_BAS) 
		{ 
			i--;
			printf("i= %d",i);
		}
	}
	S.n=i;
	return S;
}

void dessine_un_mur(SLIDER S,int n)
{
	afficher_murs(S);
}

SLIDER place_mur(FILE * f, int fl,POINT p,int n, SLIDER S)
{
	S.m.murx[n]=p.x/TAILLE_CASE; S.m.mury[n]=p.y/TAILLE_CASE;
	if (fl==FLECHE_HAUTE) S.m.type[n]=0;
	if (fl==FLECHE_DROITE) S.m.type[n]=3;
	if (fl==FLECHE_BAS) S.m.type[n]=6;
	if (fl==FLECHE_GAUCHE) S.m.type[n]=9;
	fprintf(f,"%d %d %d\n",S.m.murx[n],S.m.mury[n],S.m.type[n]);
	dessine_un_mur(S,n);
	
	return S;
}

SLIDER ecrire_murs(FILE * f,SLIDER S)
{
	int a,fl,n; char c; POINT p;
	a=n=0;
	S.m.murx = malloc ((S.n) * sizeof (int));
    S.m.mury = malloc ((S.n) * sizeof (int));
    S.m.type = malloc ((S.n) * sizeof (int));
    
	while(a!= EST_CLIC && n!=S.n){
	a = wait_key_arrow_clic (&c, &fl, &p);
		while(a!= EST_FLECHE) a = wait_key_arrow_clic (&c, &fl, &p);
    S=place_mur(f,fl,p,n,S);
    n++;
	}
	return S;
}

void editeur(SLIDER S, int L,int H,char* nom)
{
	FILE * f=NULL;
	f=fopen(nom,"w+");
	ecrire_taille_init(f,L,H,S);
	ecrire_position_slider(f,S);
	ecrire_position_sortie(f,S);
	ecrire_nb_murs(f,S);
	fclose(f);
}
