#include <stdio.h>

#include <locale.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#include <stdint.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    uint16_t digit, Sum, Rem, MOD, counter;

    printf("Input a digit: \n");
    
    scanf("%hu",&digit);

    while(digit >= 1U)
    {
        MOD = digit % 2U;

        Rem += digit / 2U;

        Sum += (2U * (MOD + Rem));

        ++counter;

        break;
    }
    printf("Output:\nThe digit, %hu;\n and its pow: %hu", Sum, --counter);


    
    return 0UL;
}