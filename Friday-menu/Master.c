#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    uint_fast32_t Number = 0UL, counter = 0U, I = 0U;

    printf("input a digit: \n");

    scanf("%Lu", &Number);

    for(I; I <= Number; ++I)
    {
        bool isPrime = 1UL;

        for(counter = 2UL; counter <= I; ++counter)
        {
            if(I % counter == 0UL)
            {
                isPrime = 0UL;
            }
            
        }
         if(isPrime == 1UL){
                printf("The simple digits are: %lu\n", I);
            }
    }

   
     return 0ULL;
}