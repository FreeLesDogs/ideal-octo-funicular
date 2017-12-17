#include "mes_types.h"

void initialiser_affichage (SLIDER S) //Initialise la fenetre
{
	init_graphics(Taille_Case*S.L,Taille_Case*S.H);
}

void afficher_grille (SLIDER S) //Affiche le quadrillage
{
  int i;POINT p1,p2;
	p1.x=0;p1.y=0;
	p2.x=0;p2.y=Taille_Case*S.H;
	
	for (i=0;i<S.L;i++)
		{
			draw_line(p1,p2,rouge);
			p1.x+=Taille_Case;	
			p2.x=p1.x;
		}
	p1.x=0;p1.y=0;
	p2.x=Taille_Case*S.L;p2.y=0;
	
	for (i=0;i<S.H;i++)
		{
			draw_line(p1,p2,rouge);
			p1.y+=Taille_Case;p2.y=p1.y;
		}
		
}

void afficher_murs (SLIDER S)//Affiche les murs
{
	int i=0;POINT p1,p2;
  
	for(i=0;i<S.N;i++)
	{
		if (S.murz[i] == 0)
		{
		  p1.x = (S.murx[i]) * Taille_Case;
		  p2.x = p1.x + Taille_Case;
		  p1.y = p2.y = (S.mury[i]) * Taille_Case + Taille_Case;
		}
		if (S.murz[i] == 6)
		{
		  p1.x = (S.murx[i]) * Taille_Case;
		  p2.x = p1.x + Taille_Case;
		  p1.y = p2.y = (S.mury[i]) * Taille_Case;
		}
		if (S.murz[i] == 3)
		{
		  p1.y = (S.mury[i]) * Taille_Case;
		  p2.y = p1.y + Taille_Case;
		  p1.x = p2.x = Taille_Case + (S.murx[i]) * Taille_Case;
		}
		  if (S.murz[i] == 9)
		{
		  p1.y = (S.mury[i]) * Taille_Case;
		  p2.y = p1.y + Taille_Case;
		  p1.x = p2.x = (S.murx[i]) * Taille_Case;
		}
		  draw_line (p1,p2,blanc);
		  
    }
}

void
afficher_le_slider (SLIDER S) //Affiche le Slider
{
  draw_fill_circle (S.ps,25,bleu);
}

void
effacer_le_slider (SLIDER S) //Efface le Slider
{
  draw_fill_circle (S.ps,25,noir);
}


void
afficher_sortie (SLIDER S) //Affiche la sortie
{

  POINT p1, p2;
  p1.x = (S.sx * Taille_Case);
  p1.y = (S.sy * Taille_Case);
  p2.x = (S.sx * Taille_Case)+ Taille_Case;
  p2.y = (S.sy * Taille_Case)+ Taille_Case;
  draw_fill_rectangle (p1, p2, white);
}

void
afficher_slider (SLIDER S) //Affiche tout
{
  initialiser_affichage (S);
  afficher_grille (S);
  afficher_murs (S);
  afficher_le_slider (S);
  afficher_sortie (S);
}

void affichage(SLIDER S)
{
  afficher_grille (S);
  afficher_murs (S);
  afficher_le_slider (S);
}


void finir_affichage (SLIDER S)
{
  fill_screen(black);
  POINT p; 
  p.x=(S.L*Taille_Case)/2;
  p.y=(S.H*Taille_Case)/2;
  aff_pol_centre("FELICITATIONS !!!!",50,p,blanc);
}
