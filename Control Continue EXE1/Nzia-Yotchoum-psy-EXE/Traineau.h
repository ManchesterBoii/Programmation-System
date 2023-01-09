


#ifndef TRAINEAU_H
#define TRAINEAU_H
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "Chien.h"


typedef struct{

    char* nomMusher;
    int nbrChien;
    Chien * ListeGauche[NB_MEUTE_MAX];
    Chien * ListeDroite[NB_MEUTE_MAX];
    
}traineau;



int creerTraineau(traineau ** T, char* nomMusher, int nbrChien, Chien * ListeGauche[], Chien * ListeDroite[]);
void afficherTraineau(traineau * T);
void detruireTraineau(traineau ** T);










#endif






