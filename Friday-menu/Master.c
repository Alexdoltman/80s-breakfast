#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    /* Задача: Для двух положительных чисел, введенных пользователем, 
    необходимо напечатать в порядке возрастания все их общие делители
    */
    
    uint16_t digit, number, counter = 0U, anotherCounter, remIn;

    printf("Input two digit: ");

    scanf("%hu", &digit);

    scanf("%hu",&number);

    // создаю цикл for.

    for(counter = 1U, anotherCounter = 1U; counter <= digit && anotherCounter <= number; ++counter, ++anotherCounter)
    {
        if(digit % counter == 0U && (number % anotherCounter == 0U))
        {
            ++remIn;

            printf("Output: %hu;\n", counter);

            printf("\n\n Output: %hu;\n",anotherCounter);
        }
    }

     return 0ULL;
}