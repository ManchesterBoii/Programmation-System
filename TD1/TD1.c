#include <stdio.h>
#include <stdlib.h>


void productL(long x, long y)
{
    printf("product is %ld\n", x * y);
}

void productS(short x, short y)
{
    printf("product is %hd\n", x * y);
}

void productI(int x, int y)
{
    printf("product is %d\n", x * y);
}


// #define product(...)OVERLOAD(product, (__VA_ARGS__), \
//     (productL, (int, int)), \
//     (productS, (short, short)), \
//     (productI, (long, long)) \
// )

// #define OVERLOAD_FUNCTIONS (product)
// #define OVERLOAD_ARG_TYPES (int, long, short)

void td1_2()
{
    int x,y;
    long a,b;
    short c,d;

    printf("Enter two integers: \n");
    scanf("%d %d", &x, &y);

    printf("Enter two long ints: \n");
    scanf("%ld %ld", &a, &b);

    printf("Enter two short ints: \n");   
    scanf("%hd %hd", &c, &d);

    productL(x, y);
    productI(a, b);
    productS(c, d);
    
    printf("sizeof long: %d\n", sizeof(long));
    printf("sizeof int: %d\n", sizeof(int));
    printf("sizeof short: %d\n", sizeof(short));

} 

float TD1_3_find_averge(char* list[], int size)
{
    int i;
    float sum = 0;
    float count = 0;
    for (i = 1; i < size; i++)
    {
        if(atoi(list[i]) > 0 && atoi(list[i]) < 20)
        {
            sum += atof(list[i]);
            count++;

        }
    
    }
    return sum / count;
}





int main(int argc, char* argv[]){

    // td1_2();
    printf("The Average all of the inputed numbers between 0 and 20 is: %.3f", TD1_3_find_averge(argv, argc));



    return 0;
}