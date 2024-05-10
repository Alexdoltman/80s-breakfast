#include <stdio.h>

#include <math.h>

#include <stdint.h>

#include <stdbool.h>

#include <locale.h>

int main()
{
    char *locale = setlocale(LC_ALL, "En-GB");

     float Velocity, Timer, Angle;

     const float G = 10.0F;

     float a = 0.0f; // The alpha angle. 

     printf("Input a V, time and an angle: \n");

     scanf("%f",&Velocity);

     scanf("%f",&Timer);

     scanf("%f", Angle);

     printf("Your speed in km/h is: %0.1f\n, Your time  is in seconds: %0.2f,\n and your angle is in degree: %0.3f.\n", Velocity, Timer, Angle);

     if(fabs(a =(G * Timer) / 2.0f * Velocity) < 0.0f) 
     {

        float Result = asin((G * Timer) / 2.0f * Velocity);

        float Change = ((Result *90.0F) / 3.140F);

        a = Change;

        printf("The angle is: %0.1f degrees\n", a);
     }
     return 0ULL;
}