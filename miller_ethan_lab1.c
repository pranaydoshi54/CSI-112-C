/*
 * Miller, Ethan 
 * Lab 1, CSCI 112
 * 1/23/17
 */
 #include <stdio.h>

 int
 main(void)
 {
    /* declare required variables */
    double celsius, fahrenheit;

    /* get the temperature in Celsius */
    printf("Enter a temperature in degrees Celsius: ");
    scanf("%lf", &celsius);
	
    /* convert to Fahrenheit */
    fahrenheit = (1.8 * celsius) + 32;	

    /* print out the temp in Fahrenheit */
    printf("That is %.2lf Fahrenheit \n", fahrenheit);

    /* get the temperature in Fahrenheit */
    printf("Enter a temperature in degrees Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    /* convert to celsius */
    celsius = ((fahrenheit - 32) * (5.0/9.0));

    /* print out the temp in Celsius */
    printf("That is %.2lf Celsius \n", celsius);

    /* exit with no errors */
    return(0);
 }
