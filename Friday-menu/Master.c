#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    uint32_t digit;

    printf("Input a digit: \n"); 

    scanf("%lu", &digit);

    for(uint32_t m = 0UL; m < digit - 2UL; ++m)
    {
        for(uint32_t k = 0UL; k <= ((digit - m) / 2UL); ++k)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n-----------------------------\n");

    for(uint32_t m = digit; m > 0UL; --m){
        for(uint32_t n = digit; 2U * n > 0UL; --n){
            printf("*");
        }
        printf("\n");
    }

    

   
     return 0ULL;
}