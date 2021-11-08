#include <stdio.h>

#define TVA 20
#define TAILLE 20
#define NOTE_MAX 20
#define NOTE_MIN 0

void affiche_TVA();
void exemple_code();
void constantes_nommees();

int main(int argc, char* argv[]){
    affiche_TVA();
    exemple_code();
    constantes_nommees();
    return 0;
}

float calcule_TVA(float prixHT){
    return ((prixHT * TVA)/ 100);
}

void affiche_TVA(){
    float HT;
    scanf("%f", &HT);
    HT= HT+calcule_TVA(HT);
    printf("prix TTC = %.2f\n", HT);
}

void exemple_code(){
    int somme;
    int a;
    int b;

    printf("Entrez deux entier separes par un blanc\n");
    scanf("%d %d", &a, &b);

    if (a>TAILLE){
        int c;
        c = a-TAILLE;
        a = 2*c;
    }
    somme = a+b;

    printf("La somme est %d\n", somme);
}

void constantes_nommees(){
    int note;
    scanf("%d", &note);
    if ((note<NOTE_MIN) || (note>NOTE_MAX)){
        printf("Note saisie incorrecte. La note doit etre en %d et %d \n", NOTE_MIN, NOTE_MAX);
    }
 
}
