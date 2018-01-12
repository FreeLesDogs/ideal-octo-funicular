NOM=PROJET_IN301

all: a.out

#Pour lancer l'executable
test: a.out 
	./a.out fichier1.slider
ecrire:slider
	./a.out -c 8 8 creation.slider
# Edition de liens
a.out: slider.o lire_ecrire.o afficher.o deplacements.o listes_memo.o 
	gcc *.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h afficher.h listes_memo.h
	gcc -c -Wall `sdl-config --cflags` slider.c

lire_ecrire.o: lire_ecrire.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` lire_ecrire.c

afficher.o: afficher.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` afficher.c

listes_memo.o: listes_memo.c mes_types.h afficher.h
	gcc -c -Wall `sdl-config --cflags` listes_memo.c	

deplacements.o: deplacements.c mes_types.h afficher.h
	gcc -c -Wall `sdl-config --cflags` deplacements.c
	
#Pour ouvrir tous les fichiers dans Geany
editeur:
	geany Makefile *.c mes_types.h fichier1.slider &

# Pour creer le zip 
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
#	cp -f *.slider $(NOM)
	zip $(NOM).zip $(NOM)/*
#	rm -fr $(NOM)

clean:
	rm -f *.o
	rm -f a.out
git:
	make clean
	git add *
	git commit  
	git push
