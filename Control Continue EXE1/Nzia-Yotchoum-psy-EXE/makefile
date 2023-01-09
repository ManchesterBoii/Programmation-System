all: Chien.o Traineau.o GestionMucher.o 
	gcc Chien.o Traineau.o GestionMucher.o -o gest

Chien.o: Chien.c Chien.h
	gcc -c Chien.c

Traineau.o: Traineau.c Traineau.h
	gcc -c Traineau.c Chien.h

GestionMucher.o: GestionMucher.c Chien.h Traineau.h
	gcc -c GestionMucher.c