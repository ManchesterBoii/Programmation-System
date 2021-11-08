#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {NIVEAU_CONSTANT, EN_MONTEE, EN_DESCENTE} profil;
typedef enum {NOMINAL,ALERTE,DETRESSE} etat;

const char* profil_str[] = {"NIVEAU_CONSTANT","EN_MONTEE","EN_DESCENTE"};
const char* etat_str[] = {"NOMINAL","ALERTE","DETRESSE"};




typedef struct {
    char *code;
    float altitude;
    float cap;
    float speed;
    profil profil;
    etat etat;
} plane;


int main(){
    printf("%d", NIVEAU_CONSTANT);
    return 0;


}