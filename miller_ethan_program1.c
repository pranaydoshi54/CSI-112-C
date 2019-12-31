/*Miller, Ethan
 * Program 1, CSCI 112
 * 1/20/17
 */

//Include Libraries
#include <stdio.h>
#include <math.h>
#include <float.h>

//Declare Functions
int get_input(void);
int is_valid(int a);
int print_pattern(int a);

//Main Function
int main(void)
{
 int y = 0;
 int x;
 do{//Do while loop for whether or not input is valid
 x = get_input();
 y = is_valid(x);
 }while(y == 0);

 print_pattern(x);//Call to print pattern
}

//Function for getting user input 
int get_input(void)
{
 int x;
 printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
 scanf("%d", &x);
 return x;
}

//Function to test if user input is valid
int is_valid(int a)
{
 if(a > 9)
 {
  printf("You have entered a number greater than 9. Please try again.\n");
  return 0;
 }
 else if(a % 2 == 0)
 {
  printf("You have entered an even number. Please try again.\n");
  return 0;
 }
 else if(a < 1)
 {
  printf("You have entered a number less than 1. Please try again.\n");
  return 0;
 }
 else
 {
  return 1;
 }
}

//Function to print pattern
int print_pattern(int a)
{
 for (int i = 1; i <= a; i += 2)//For loop for top half of diamond
 {
  if(i != a)//If statement to check middle line
  {
  printf("%*s", a - i," ");//Print spaces
  for (int j = 1; j <= i; j++)//For loop to print numbers
  {
   printf("%d ", j);//Prints numbers
  }
  printf("\n");//Prints new line
  }
  else//Condition for middle line
  {
   for (int j = 1; j <= i; j++)//For loop to print middle line fo numbers
   {
    printf("%d ", j);//Prints middle line of numbers
   }
   printf("\n");//Prints new line
  }
 }

 for(int i = a - 2; i > 0; i -= 2)//For loop for bottom half of diamond
 {
  printf("%*s", a - i, " ");//Prints spaces 
  for (int j = 1; j <= i; j++)//For loop to print numbers
  {
   printf("%d ", j);//Prints numbers
  }
  printf("\n");//Prints new line
 }
 return 0;//Returns with no issues
}

