
/*
*Miller, Ethan
*Lab 2, CSCI 112
*1/31/17
*/
#include <stdio.h>

/*Declare Functions*/
double get_input(void);
double get_next(double a, double b);
void print_result(double y);

int main(void)
{
 /*Declare Variables*/
 double x1, x2, x3, x4, x5;
 
 /*Execute Functions*/
 x1 = get_input();
 x2 = get_input();
 x3 = get_next(x1, x2);
 x4 = get_next(x2, x3);
 x5 = get_next(x3, x4);
 print_result(x5);

 return(0);

}

double get_input(void)
{
  /* Declare required variables */
  double num;
  printf("Enter a number >");
  scanf("%lf", &num);
  return num;
}

double get_next(double a, double b)
{
  /*Declare variables*/
  double x;
  x = (a / 2) + (3 * b);
  return x;	
}

void print_result(double y)
{
  /*Print out the value*/
  printf("The result is %.2lf \n", y);
  
}
