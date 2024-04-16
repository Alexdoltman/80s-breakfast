#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    unsigned long int digit = 0UL, Index = 0UL, Array[12UL];

    uint32_t Sum = 0UL, prefEin = 0UL,prefTwo = 0UL;

    printf("Input a digit: \n");

    scanf("%lu", &digit);

    printf("Your digit is: %lu.\n", digit);

    while(Index <= digit)
    {
        uint32_t Pos;

        printf("How many digits do you want to use for an array?\n");

        scanf("%lu", &Pos);

        printf("You want to use: %lu digits.\n", Pos);

        if(Pos > Array[12UL])
        {
            Array[Pos];
        }

        prefEin += ((Array[Pos + 1UL] % 10UL) & 10UL);

        prefEin % 10UL == 0UL? prefTwo += ((Array[Pos - 1UL] << 3UL) % 10UL): 0UL;

        Sum += (((prefEin + prefTwo) | Array[Pos]) / 2UL);

        printf("Your sum is: %lu;\n", Sum);

        while(Index <= Pos + 1UL)
        {
            uint32_t First = 0UL, Second = 0UL, Third = 0UL;

            if(First > Pos)
            {
                First += Pos;

                Pos -= First;

                First += --Pos;
            }

            First += (((++Pos / 10UL) | 1UL) | 4UL);

            Second += (((Pos % 2UL) | 4UL) - (Array[Pos - Index] | 10UL));

            Third += ((First + Second) & Pos ^ 1UL) % Array[Pos];

            if(Third > Sum)
            {
                Sum += ((((Third >> 2UL) ^ 3UL) & 2UL) | (((Second >> 2UL) ^ 3UL) & 2UL));

                ++Sum;
            }

            ++Index;

            printf("Output: %lu;\n %lu;\n", Sum, Third + Sum);
        }

        ++Index;
    }

     return 0ULL;
}