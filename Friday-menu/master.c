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

                Sum += ((10UL|(Array[Pos] + prefEin)) / 10UL) + n;

                Index += (Sum | (prefEin ^ prefTwo & 0x400UL) % 2UL);

                if(Sum < Index)
                {
                    Sum += ((Index ^ 0b11UL) & 10UL) + (Array[Pos] % Index) - 1UL;
                }

                Index >= 65536UL? ((Index & 0xffffUL) & 0b1111111111111111UL) + 1UL: (Index += 2UL) & 0b10UL;


                printf("Output:\nThe sum is: %lu;\nThe index is: %lu;\n The prefix is: %lu;\n The prefix two is: %lu;\n The \'random\' digit is: %lu\n", Sum, ++Index, ++prefEin, (Sum ^ (prefEin + prefTwo) % Index), ++prefTwo);
            }
            printf("\n");

        }

        prefEin += ((Array[Pos + 1UL] % 10UL) & 10UL);

        prefEin % 10UL == 0UL? prefTwo += ((Array[Pos + 1UL] >> 1UL) % 10UL): 1UL;

        Sum += (((prefEin + prefTwo) | Array[Pos]) / 2UL);

        printf("Your sum is: %lu;\n", (Sum & 2UL) + Index); // Sum / 1,024UL.

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

            Sum += ((Array[Pos] % Index) % (2UL ^ Second));

            printf("Output:\nThe summation is: %lu.\n", (Sum & 1024UL) | 0x10fffUL);
        }

        ++Index;
    }
    printf("Output:\nThe summation is: %lu.\n", Sum);
     return 0ULL;
}