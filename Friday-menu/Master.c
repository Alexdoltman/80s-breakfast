#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    uint32_t digit, Sum;

    uint32_t *F; // it is an array = F[x];

    printf("Input an amout of digits: \n");

    scanf("%lu",&digit);

    F[digit];

    for(uint32_t n = 1ul; n < digit + 1ul; ++n)
    {
        Sum += F[Sum - 1ul] += F[digit - 2UL];
    }
    printf("Output: %lu.\n", Sum);
     
     return 0ULL;
}