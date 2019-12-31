/*
 * Miller, Ethan
 * Lab 2, CSCI 112
 * 1/31/17
 */

#include <stdio.h>
#include <math.h>
#include <float.h>

//Declare Functions
int get_n(void);
double get_input(void);

int main(void)
{

 //Declare Variables
 int  N = get_n();
 double lowest = DBL_MAX, highest = DBL_MAX;
 double current, sum, sumSquares, range, average, stdDev;

 //For loop for N values 
 for(int i = 0; i < N; i++)
 {
  current = get_input();
  if (current < lowest){
   lowest = current;
  }else{
   highest = current;
  }
  
  //Calc Sum
  sum = sum + current;

  //Calc sum of the squares for Standard Deviation
  sumSquares = sumSquares + pow (current, 2.0);
 }
 // Calc Range
 range = highest - lowest;

 //Set to Zero if 0 is inputed
 if (N == 0){
  lowest = 0;
  highest = 0;
  range = 0;
  average = 0;
  stdDev = 0;
 }else{
  //Calc Average and Standard Deviation
  average = sum / N;
  stdDev = sqrt ( (sumSquares / N) - pow (average, 2.0));
 }

 //Print out all reuslts
 printf("The Highest is: %.3lf \n", highest);
 printf("The Lowest is: %.3lf \n", lowest);
 printf("The Average is: %.3lf \n", average);
 printf("The Range is: %.3lf \n", range);   
 printf("The Standard Deviation is: %.3lf \n", stdDev);
 return(0);
}

//Function to get N
int get_n(void)
{
int  N = -1;
 do
  {
    printf("Enter a Value for N that is >= 0: ");
    scanf("%d", &N);
    if(N < 0)
    {
     printf("Invalid value for N \n");
    }
    else
    {
     break;
    } 	 
  } while(N < 0);
  return(N);
}  

//Function to get inputed values
double get_input()
{

  /* Declare required variables */
  double num;
  printf("Enter a number: ");
  scanf("%lf", &num);
  return num;
}
