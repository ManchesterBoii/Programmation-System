all: article.o gestion.o
	gcc -o article.o gestion.o -o gest

article.o: article.c article.h
	gcc -c article.c

gestion.o: gestion.c article.h
	gcc -c gestion.c



