#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "article.h"
#include "article.c"



int main(int argc, char *argv[])
{  

    

    int nbArticles = 10;
    int choice;
    int icode;
    int iTaille;
    char sDesignation[TAILLE];
    float fPu;
    int count = 0;

    Article * articles[nbArticles];


    printf("1 - ajouterArticle\n");
    printf("2 - afficherArticles\n");
    printf("3 - supprimerArticle\n");
    printf("4 - quitter\n");
    scanf("%d%*c", &choice);


   while(choice != 4){

        

        switch (choice){

            case 1:
                printf("Enter Code: ");
                scanf("%d%*c", &icode);
                printf("Enter Designation: ");
                scanf("%s", sDesignation);
                printf("Enter Taille: ");
                scanf("%d%*c", &iTaille);
                printf("Enter Prix: ");
                scanf("%f%*c", &fPu);
                creerArticle(&articles[count], icode, sDesignation, iTaille, fPu);
                count++;
                break;
            case 2:
                for (int i = 0; i < count; i++){
                    afficherArticle(articles[i]);
                }
                break;

            case 3:
                for (int i = 0; i < count; i++){
                        detruireArticle(&articles[i]);
                }
                count--;
                
                break;

            case 4:
                printf("Au revoir\n");
                break;
            default:
                printf("Erreur\n");
                break;


        }
        
            printf("1 - ajouterArticle\n");
    printf("2 - afficherArticles\n");
    printf("3 - supprimerArticle\n");
    printf("4 - quitter\n");
    printf("\n");


    scanf("%d%*c", &choice);


    }
  
   
    return 0;
}






