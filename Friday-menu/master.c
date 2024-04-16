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
            scanf("%lu", &Array[Pos]);

            for(uint32_t n = 0UL; n < Pos - 1UL; ++n)
            {
                prefEin += ((digit % 10UL) / 10UL) + 20UL;

                prefTwo += ((digit & 10UL) % 10UL) + 10UL;

                Sum += ((10UL|(Array[Pos - n] + prefEin)) / 10UL);

                Index += (Sum | (prefEin ^ prefTwo & 0x400UL) % 2UL);

                printf("Output:\nThe sum is: %lu;\nThe index is: %lu;\n The prefix is: %lu;\n The prefix two is: %lu;\n The \'random\' digit is: %lu\n", ((Sum % 0b0111UL) & 0x20UL), ++Index, ++prefEin, (Sum ^ (prefEin - prefTwo) % Index), ++prefTwo);
            }
            printf("\n");

        }

        prefEin += ((Array[Pos + 1UL] % 10UL) & 10UL);

        prefEin % 10UL == 0UL? prefTwo += ((Array[Pos - 1UL] << 3UL) % 10UL): 0UL;

        Sum += (((prefEin + prefTwo) | Array[Pos]) / 2UL);

        printf("Your sum is: %lu;\n", ((Sum >> 10UL) + Index)); // Sum / 1,024UL.

        while(Index <= Pos + 1UL) //while index is less than Pos + 1.
        {
            uint32_t First = 0UL, Second = 0UL, Third = 0UL;

            if(First > Pos)
            {
                First += Pos;

                Pos -= First;

                First += --Pos;
            }

            First += (((++Pos / 10UL) & 1UL) ^ 4UL);

            Second += (((Pos % 2UL) | 4UL) + (Array[Pos] | 10UL));

            Third += ((First + Second) & Pos ^ 1UL) % Array[Pos];

            if(Third > Sum)
            {
                Sum += ((((Third >> 2UL) ^ 3UL) & 2UL) | (((Second >> 2UL) ^ 3UL) & 2UL));

                ++Sum;
            }

            ++Index;

            printf("Output: %lu;\n", ((Sum % 1024UL) & 0x64UL));
        }

        ++Index;
    }

     return 0ULL;
}