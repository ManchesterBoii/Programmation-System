#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "article.h"


// int creerArticle(Article ** article, int icode, char * sDesignation, int iTaille, float fPu){
//     Article * a = malloc(sizeof(Article));
//     if(a == NULL){
//         return -1;
//     }
//     a->iCode = icode;
//     // a->sDesignation = malloc(sizeof(char)*(strlen(sDesignation)+1));
//     // if(a->sDesignation == NULL){
//     //     return 1;
//     // }
//     strcpy(a->sDesignation, sDesignation);
//     a->iTaille = iTaille;
//     a->fHT = fPu;
//     *article = a;
//     return 0;
// }


int creerArticle(Article ** article, int icode, char * sDesignation, int iTaille, float fPu){
    *article = malloc(sizeof(Article));
    if(*article == NULL){
        return -1;
    }
    (*article)->iCode = icode;
    strcpy((*article)->sDesignation, sDesignation);
    (*article)->iTaille = iTaille;
    (*article)->fHT = fPu;

    return 0;
}

void afficherArticle(Article *article){
    if( article == NULL){
        printf("NULL\n");
    }
    else{
        printf("Article -\ncode: %d\nDesignation: %s\nTaille: %d\nPrix: %.2f\n", article->iCode, article->sDesignation, article->iTaille, article->fHT);
    }


}
void detruireArticle (Article ** pArt){
    if (*pArt != NULL){
        Article * a = *pArt;
        free(a->sDesignation);
        free(a);
        *pArt = NULL;
    }
    
}




