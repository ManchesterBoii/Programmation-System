#include <stdio.h>

int main(){
    int i, j, k=0, l, m, n ;

    printf("Entres les valeurs : ");
    scanf("%d%c", &i);
    scanf("%d%c", &j);

    if (i>j){l=n=i; m=j;}
    else {l=n=j; m=i;}

    while(l>m){
        k++;
        l-=m;
    }

    printf("Resultat %d %d %d %d",i,j,k,l);

}