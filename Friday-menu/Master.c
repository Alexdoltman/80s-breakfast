#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    /*
        Задача: Дано целое число k (1 ≤ k ≤ 365). Присвоить целочисленной величине n значение 1, 2, ..., 6 или 0 в зависимости от того, на какой день недели (понедельник, 
 
12 Глава 2
вторник, ..., субботу или воскресенье) приходится k-й день года, в котором 
1 января:
а) понедельник;
б) вторник;
в)* d-й день недели (если 1 января— понедельник, то 
d 1
, если вторник —
d 2 , ..., если воскресенье — d 7
).
    */

   uint16_t n, // от французского слова numéro, то есть номер
            k; // это целое число.
    
    printf("Input a digit: ");

    scanf("%hu", &k);

    if(k >= 1U && k <= 365U)
    {
        n += k % 7U;

        if((k % 7U) >= 1U && (k % 7U) <= 7U)
        {
           switch(n)
           {
            case 1U:
                printf("The Monday!\n And its number is %hu\n", n);
                return 0U;
                break;

                case 2U:
                printf("The Tuesday!\nAnd its number is %hu\n",n);
                break;

                case 3U:
                printf("The Wednesday!\nAnd it's number is %hu\n",n);
                break;

                case 4U:
                printf("The Thirsday!\nAnd it's number is %hu\n",n);
                break;

                case 5U:
                printf("The Friday\nAnd it's number is %hu\n",n);
                break;

                case 6U:
                printf("The Saturday\nAnd it's number is %hu\n",n);
                break;

                case 7U:
                printf("The Sunday\nAnd it's number is %hu\n", n);
                break;

                default:
                return - 1l;
                break;
           }
        }

        else{
            perror("You have got an error!\n");
            return -1;
        }

    }

     return 0ULL;
}