NOM=ABELLI

all:slider

#Pour lancer l'executable
test:slider 
	./slider fichier1.slider
ecrire:slider 
	./slider -c 8 8 creation.slider
dir:slider
	./slider dir_slider/1.slider
	./slider dir_slider/2.slider
	./slider dir_slider/3.slider
	./slider dir_slider/4.slider
	./slider dir_slider/5.slider
	
# Edition de liens
slider: slider.o lire_ecrire.o afficher.o deplacements.o fonction_pile.o 
	gcc *.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h afficher.h fonction_pile.h
	gcc -c -Wall `sdl-config --cflags` slider.c

lire_ecrire.o: lire_ecrire.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` lire_ecrire.c

afficher.o: afficher.c mes_types.h
	gcc -c -Wall `sdl-config --cflags` afficher.c

fonction_pile.o: fonction_pile.c mes_types.h afficher.h
	gcc -c -Wall `sdl-config --cflags` fonction_pile.c	

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
	rm -f slider
git:
	make clean
	git add *
	git commit  
	git push
