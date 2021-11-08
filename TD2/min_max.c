#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    long nombre;

    printf("Entrez un nombre : ");
    scanf("%ld", &nombre);
    long max = nombre;
    long min = nombre;



    while (nombre != -1){

        if (nombre > max)
        {
            max = nombre;
        }else if (nombre < min)
        {
            min = nombre;
        }
        printf("Entrez un nombre : ");
        scanf("%ld", &nombre);
   
    }
    printf("Le nombre max est %ld\n", max);
    printf("Le nombre min est %ld\n", min);
   
    return 0;

}
