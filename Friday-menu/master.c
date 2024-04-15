#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

          uint32_t Number = {0UL}, type;

     float Array[5UL];

     while(Number <= *Array)
     {
        scanf("%lu", &Array[Number]);

        ++type;
     }
     for(uint32_t j = 0UL; j < Number; ++j)
     {
        if(Array[j] < 5UL)
        {
            printf("The index, [%lu] and its number: %lu\n", j, Array[j]);
        }
        printf("Output: %lu - [%lu];\n", j, Array[j]);
     }

    return 0ULL;
}