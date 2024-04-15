#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    unsigned long int num, nLine = 0Ul, SumOfn;

    printf("Input a digit: \n");

    scanf("%lu", &num);

    for(unsigned long int n = 0UL; n < num - 1UL; ++n)
    {
        for(nLine = 1UL; nLine < num - 1UL; ++nLine)
        {
            SumOfn += ((2UL * (n + SumOfn)) - 1UL);

            printf("Output: %lu;\n", SumOfn);
        }
        printf("\n");
    }

    return 0ULL;
}