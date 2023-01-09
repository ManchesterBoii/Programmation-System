all: Gestionfichier.o GestionNotes.c 
	gcc GestionNotes.c Gestionfichier.o -o gestionNote
Gestionfichier.o: Gestionfichier.c
	gcc -c Gestionfichier.c
clean:
	rm *.o gestionNote
	