#include "Chien.h"
// #include "Chien.c"
#include "Traineau.h"
// #include "Traineau.c"

void Traineau();

int main(int argc, char *argv[]){
    Chien * dChien[NB_MEUTE_MAX];
    int iNbChiens = 0;
    creerChien(&dChien[0],"Papiou",2,2,20.30);
    iNbChiens++;
    creerChien(&dChien[1],"Wolfy",1,1,25.90);
    iNbChiens++;
    creerChien(&dChien[2],"Karnik",3,3,21.40);
    iNbChiens++;
    creerChien(&dChien[3],"Waazaa",2,4,30.70);
    iNbChiens++;

    afficheTousLesChiens(dChien,iNbChiens);


    for (int i = 0; i < iNbChiens; i++)
    {
        detruireChien(&dChien[i]);
    }


    Traineau();

    return 0;


}


void afficheTousLesChiens(Chien * dChien[], int iNbChiens){
    for(int i=0;i<iNbChiens;i++){
        afficherChien(dChien[i]);
        printf("\n");
    }
}


void Traineau(){

    printf("Traineau:\n");

    Chien * LeftChien[NB_MEUTE_MAX];
    Chien * RightChien[NB_MEUTE_MAX];
    traineau * dTraineau[2];

    

    int iNbch = 3;

    creerChien(&LeftChien[0],"Papiou",2,2,20.30);
    creerChien(&LeftChien[1],"Wolfy",1,1,25.90);
    creerChien(&LeftChien[2],"Bear",1,4,31.80);

    creerChien(&RightChien[0],"LolyPop",1,2,19.30);
    creerChien(&RightChien[1],"Betty",3,1,27.40);
    creerChien(&RightChien[2],"Beaver",2,4,32.70);

    creerTraineau(&dTraineau[0],"Nicholas",iNbch,LeftChien,RightChien);

    afficherTraineau(dTraineau[0]);

    detruireTraineau(&dTraineau[0]);







}