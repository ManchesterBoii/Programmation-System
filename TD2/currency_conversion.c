#include <stdio.h>
#include <stdlib.h>

#define USD 1.1754
#define CAD 1.56306
#define CHF 1.07879
#define JYE 124.735
#define GBP 0.914021
#define MXN 25.2636

void menu();
void convert(char choice, float amount);



int main(int argc, char* argv[]){

    menu();
    return 0;
}


void menu(){

    float amount;
    char choice;
    printf("Here are the conversiton rates by currency and their symbols\n");
    printf("USD (u): $%f\n", USD);
    printf("CAD (c): $%f\n", CAD);
    printf("CHF (h): $%f\n", CHF);
    printf("JYE (j): $%f\n", JYE);
    printf("GBP (g): $%f\n", GBP);
    printf("MXN (m): $%f\n", MXN);
    printf("Enter (-1,q) to quit\n");
    printf("Enter Euro amount, and the desired currency\n");
    printf("Example input (345, u):\n");
    scanf("%f, %c", &amount, &choice);
    while (choice != 'q'){
        convert(choice, amount);
        printf("Enter Euro amount, and the desired currency\n");
        scanf("%f, %c", &amount, &choice);
    };
}

void convert(char choice, float amount){

    switch (choice)
    {
    case 'u': printf("The conversion to USD is %.3f\n",amount * USD);
        break;
    
    case 'c': printf("The conversion to CAD is %.3f\n",amount * CAD);
        break;
    case 'h': printf("The conversion to CHF is %.3f\n",amount * CHF);
        break;
    case 'j': printf("The conversion to JYE is %.3f\n",amount * JYE);
        break;
    case 'g': printf("The conversion to GBP is %.3f\n",amount * GBP);
        break;
    case 'm': printf("The conversion to MXN is %.3f\n",amount * MXN);
        break;
    default: printf("Invalid input\n");
        break;
    }




}
