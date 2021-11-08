#include <stdio.h>
#include <stdlib.h>



long puissance(long x, long y)
{
    float resultat = 1;
    int i;
    for (int i = 0; i < y; i++)
    {
        resultat = resultat * x;
    }
    return resultat;
}

long recursive_puissance(long x, long y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * recursive_puissance(x, y - 1);
    }
}

int main(int argc, char *argv[]){

    long x;
    long y;

    printf("Saissisez un nombre x : ");
    scanf("%ld", &x);
    printf("Saissisez un nombre y : ");
    scanf("%ld", &y);

    printf("La puissance de %ld par %ld est %ld\n", x, y, puissance(x, y));
    printf("(Using recursion)\nLa puissance de %ld par %ld est %ld\n", x, y, recursive_puissance(x, y));


    
    return 0;
}