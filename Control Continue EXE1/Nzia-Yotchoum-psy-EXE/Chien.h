#ifndef CHIEN_H
#define CHIEN_H


#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


#define CODE_HUSKY 1
#define CODE_MALAMUTE 2
#define CODE_GROENLANDAIS 3

#define S_HUSKY "Husky"
#define S_MALAMUTE "Malamute"
#define S_GROENLANDAIS "Groenlandais"

#define CODE_LEADER 1
#define CODE_SWING_LEADER 2
#define CODE_TEAM_DOG 3
#define CODE_WHEEL_DOG 4

#define S_LEADER "LEADER"
#define S_SWING_LEADER "SWING_LEADER"
#define S_TEAM_DOG "TEAM_DOG"
#define S_WHEEL_DOG "WHEEL_DOG"

#define NB_MEUTE_MAX 100
#define TAILLE_MAX 10


typedef enum {HUSKY = CODE_HUSKY, MALAMUTE= CODE_MALAMUTE, GROENLANDAIS = CODE_GROENLANDAIS} TypeR;
typedef enum {LEADER = CODE_LEADER, SWING_LEADER = CODE_SWING_LEADER, TEAM_DOG = CODE_TEAM_DOG, WHEEL_DOG = CODE_WHEEL_DOG} typeL;

/* Debut Declaration du Type Chien */

typedef struct {
    char nom[TAILLE_MAX];
    TypeR race;
    typeL type;
    float poids;

} Chien;


/* Fin Declaration du Type Chien */

/* Fonction de manipulation du type Chien */
int creerChien(Chien ** dChien, char *nom, TypeR race, typeL type, float poids);
void afficherChien(Chien * dChien);
void detruireChien(Chien **dChien);
void afficheTousLesChiens(Chien * dChien[], int iNbChiens);


#endif