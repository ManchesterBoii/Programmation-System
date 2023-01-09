
#include "Traineau.h"




int creerTraineau(traineau ** T, char* nomMusher, int nbrChien, Chien * ListeGauche[], Chien *ListeDroite[]){
    *T = (traineau*)malloc(sizeof(traineau));
    if(*T == NULL){
        return -1;
    }
    (*T)->nomMusher = (char*)malloc(sizeof(char)*(strlen(nomMusher)+1));
    if((*T)->nomMusher == NULL){
        return -1;
    }
    strcpy((*T)->nomMusher, nomMusher);
    (*T)->nbrChien = nbrChien;
    for (int i = 0; i < nbrChien; i++)
    {
        (*T)->ListeGauche[i] = ListeGauche[i];
        (*T)->ListeDroite[i] = ListeDroite[i];
    }
    
    return 0;
}
void afficherTraineau(traineau * T){
    printf("Musher: %s\n", T->nomMusher);
    printf("Nb de Chiens %d\n", T->nbrChien);
    for (int i = 0; i < T->nbrChien; i++)
    {
        printf("Ligne : %d\n", i);
        afficherChien(T->ListeGauche[i]);
        afficherChien(T->ListeDroite[i]);
    }
}
void detruireTraineau(traineau ** T){
    if(*T != NULL){
        free((*T)->nomMusher);
        free(*T);
        *T = NULL;
    }
   
}