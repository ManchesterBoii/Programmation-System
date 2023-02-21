#include "Chien.h"
int creerChien(Chien ** dChien, char *nom, TypeR race, typeL type, float poids){
    *dChien = (Chien*)malloc(sizeof(Chien));
    if(*dChien == NULL){
        return -1;
    }
    strcpy((*dChien)->nom,nom);
    (*dChien)->race = race;
    (*dChien)->type = type;
    (*dChien)->poids = poids;
    return 0;
}
void afficherChien(Chien * dChien){
    char typeR_str[3][13] = {S_HUSKY, S_MALAMUTE, S_GROENLANDAIS};
    char typeL_str[4][13] = {S_LEADER, S_SWING_LEADER, S_TEAM_DOG, S_WHEEL_DOG};
    printf(" Nom: %s  ", dChien->nom);
    printf(" Race: %s  ", typeR_str[dChien->race-1]);
    printf(" Type: %s  ", typeL_str[dChien->type-1]);
    printf(" Poids: %.2f (kg)\n", dChien->poids);
}
void detruireChien(Chien **dChien){
    if(*dChien != NULL){
        free(*dChien);
    }
    *dChien = NULL;
}
