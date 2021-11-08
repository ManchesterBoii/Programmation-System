#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Here are all the numbers from 0 to %d: ", number);

    for(int i = 0; i <= number; i++){
        printf("%d ", i);
    }
  




    return 0;
}