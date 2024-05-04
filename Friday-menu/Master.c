#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

    const float Pi = 3.1415926535f; // Это число P.

    printf("Output: %0.001f\n", Pi);

     return 0ULL;
}