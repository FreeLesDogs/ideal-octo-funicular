NOM=PROJET_IN301

all: slider

#Pour lancer l'executable
test: slider 
	./slider fichier1.slider
ecrire:slider
	./slider creation.slider
# Edition de liens
slider: slider.o lire_ecrire.o afficher.o deplacements.o listes_memo.o 
	gcc *.o  -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h afficher.h listes_memo.h editeur.h
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
	geany Makefile *.c mes_types.h

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
	rm -f slider
git:
	make clean
	git add *
	git commit 
	git push
