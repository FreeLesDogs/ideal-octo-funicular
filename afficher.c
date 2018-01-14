#include "mes_types.h"

void initialiser_affichage(SLIDER S) //Initialise la fenetre
{
	init_graphics(TAILLE_CASE*S.L,TAILLE_CASE*S.H);
}
COULEUR couleur_alea()
{
	COULEUR c=0;
	int m;
	m=alea_int(12);
	if(m==0) c=silver;
	else if(m==1) c=aqua;
	else if(m==2) c=black;
	else if(m==3) c=blue;
	else if(m==4) c=magenta;
	else if(m==5) c=green;
	else if(m==6) c=gray;
	else if(m==7) c=lime;
	else if(m==8) c=marron;
	else if(m==9) c=navy;
	else if(m==10) c=olive;
	else if(m==11) c=purple;
	else if(m==12) c=red;
	else if(m==13) c=teal;
	else if(m==14) c=yellow;
	return c;
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
	COULEUR c;
	c=couleur_alea();
	fill_screen(c);
	POINT p; 
	p.x=S.L*38;
	p.y=(S.H*50);
	aff_pol_centre("SLIDER",18*S.L,p,blanc);
	p.y=(S.H*35);
	aff_pol_centre("cliquez pour jouer",8*S.L,p,blanc);
	p.y=(S.H*15);
	aff_pol_centre("pour un retour en arriere appuyez sur Z",3*S.L,p,blanc);
	p.y=(S.H*10);
	aff_pol_centre("pour recommencer appuyez sur R",3*S.L,p,blanc);
	wait_clic();
}

void gagnant(SLIDER S)//quand on gagne
{	
	fill_screen(bleu);
	POINT p; 
	p.x=(S.L*TAILLE_CASE)/2;
	p.y=(S.H*TAILLE_CASE)/2;
	aff_pol_centre("GAGNE",20*S.L,p,blanc);
}

void quitter(SLIDER S,POINT p)
{
	if((S.sx*TAILLE_CASE)+5<p.x&&p.x<(S.sx*TAILLE_CASE)+TAILLE_CASE)
	{
		if((S.sy*TAILLE_CASE)+5<p.y&&p.y<(S.sy*TAILLE_CASE)+ TAILLE_CASE)
		printf("sortie");
	}
}

void afficher_slider(SLIDER S) //Affiche tout
{
  initialiser_affichage (S);
  afficher_quadrillage(S);
  afficher_murs (S);
  afficher_le_slider (S);
  afficher_sortie (S);
}
