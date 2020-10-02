/*
 * Miller, Ethan 
 * Lab 1, CSCI 112
 * 1/23/17
 */
#include <stdio.h>
#include <stdlib.h>

 int
 main(void)
 {
    /* declare required variables */
    double C, F;

    /* get the temperature in Celsius */
    printf("Enter a temperature in degrees Celsius: ");
    scanf("%lf", &C);
	
    /* convert to Fahrenheit */
    F = (1.8 * C) + 32;	

    /* print out the temp in Fahrenheit */
    printf("That is %.2lf Fahrenheit \n", F;

    /* get the temperature in Fahrenheit */
    printf("Enter a temperature in degrees Fahrenheit: ");
    scanf("%lf", &F);

    /* convert to celsius */
    C = ((F - 32) * (5.0/9.0));

    /* print out the temp in Celsius */
    printf("That is %.2lf Celsius \n", C);

    /* exit with no errors */
    return(0);
 }
