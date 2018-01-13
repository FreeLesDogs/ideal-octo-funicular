#include "mes_types.h"

void initialiser_affichage(SLIDER S) //Initialise la fenetre
{
	init_graphics(TAILLE_CASE*S.L,TAILLE_CASE*S.H);
}

void afficher_quadrillage(SLIDER S) //Affiche le quadrillage
{
  int i;POINT_D p;
	p.p1.x=0;p.p1.y=0;
	p.p2.x=5;p.p2.y=TAILLE_CASE*S.H;
	for(i=0;i<S.L;i++)
	{
		draw_fill_rectangle(p.p1,p.p2,rouge);
		p.p1.x=TAILLE_CASE+p.p1.x;	
		p.p2.x=p.p1.x+5;
	}
	p.p1.x=0;p.p1.y=0;
	p.p2.x=TAILLE_CASE*S.L;p.p2.y=5;
	
	for (i=0;i<S.H;i++)
	{
		draw_fill_rectangle(p.p1,p.p2,rouge);
		p.p1.y=TAILLE_CASE+p.p1.y;
		p.p2.y=p.p1.y+5;
	}
}

void afficher_murs (SLIDER S)//Affiche les murs
{
	int i;
	POINT_D p;
  
	for(i=0;i<S.n;i++)
	{
		if (S.m.type[i]==0)
		{
		  p.p1.x=((S.m.x[i])*TAILLE_CASE);
		  p.p2.x=p.p1.x + TAILLE_CASE;
		  p.p1.y=(S.m.y[i])*TAILLE_CASE+TAILLE_CASE;
		  p.p2.y=(S.m.y[i])*TAILLE_CASE+TAILLE_CASE+5;
		}
		if(S.m.type[i]==6)
		{
		  p.p1.x=(S.m.x[i])*TAILLE_CASE;
		  p.p2.x=p.p1.x+TAILLE_CASE;
		  p.p1.y=(S.m.y[i])*TAILLE_CASE;
		  p.p2.y=(S.m.y[i])*TAILLE_CASE+5;
		}
		if(S.m.type[i]==3)
		{
		  p.p1.y=(S.m.y[i])*TAILLE_CASE;
		  p.p2.y=p.p1.y+TAILLE_CASE;
		  p.p1.x=TAILLE_CASE+(S.m.x[i])*TAILLE_CASE;
		  p.p2.x=TAILLE_CASE+(S.m.x[i])*TAILLE_CASE+5;
		}
		if(S.m.type[i]==9)
		{
		  p.p1.y=(S.m.y[i])*TAILLE_CASE;
		  p.p2.y = p.p1.y+TAILLE_CASE;
		  p.p1.x=(S.m.x[i])*TAILLE_CASE;
		  p.p2.x=(S.m.x[i])*TAILLE_CASE+5;
		}
		  draw_fill_rectangle (p.p1,p.p2,blanc);
		  printf("mur n°%d:\n abscisse:%d ordonnee:%d type:%d\n",i+1,S.m.x[i],S.m.y[i],S.m.type[i]);
    }
}

void afficher_le_slider (SLIDER S) //Affiche la balle
{
  draw_fill_circle (S.balle,30,bleu);
}

void effacer_le_slider (SLIDER S) //Efface la balle
{
	draw_fill_circle (S.balle,30,noir);
}

void afficher_sortie (SLIDER S) //Affiche la sortie
{
	POINT_D p;
	p.p1.x=(S.sx*TAILLE_CASE)+5;
	p.p1.y=(S.sy*TAILLE_CASE)+5;
	p.p2.x=(S.sx*TAILLE_CASE)+TAILLE_CASE;
	p.p2.y=(S.sy*TAILLE_CASE)+ TAILLE_CASE;
	
	draw_fill_rectangle (p.p1,p.p2,vert);
}

void intro(SLIDER S)//message d'acceuil 
{
	initialiser_affichage(S);
	fill_screen(rouge);
	POINT p; 
	p.x=WIDTH/2;
	p.y=(HEIGHT/2)+100;
	aff_pol_centre("SLIDER",200,p,blanc);
	p.y=(HEIGHT/2)-50;
	aff_pol_centre("cliquez pour jouer",50,p,blanc);
	p.y=(HEIGHT/2)-130;
	aff_pol_centre("pour un retour en arriere appuyez sur Z",30,p,blanc);
	p.y=(HEIGHT/2)-180;
	aff_pol_centre("pour recommencer appuyez sur R",30,p,blanc);
	wait_clic();
}

void gagnant(SLIDER S)//quand on gagne
{	
	fill_screen(noir);
	POINT p; 
	p.x=(S.L*TAILLE_CASE)/2;
	p.y=(S.H*TAILLE_CASE)/2;
	aff_pol_centre("GAGNE",100,p,blanc);
}

void afficher_slider(SLIDER S) //Affiche tout
{
  initialiser_affichage (S);
  afficher_quadrillage(S);
  afficher_murs (S);
  afficher_le_slider (S);
  afficher_sortie (S);
}
