/*
 * Miller, Ethan 
 * Lab 4, CSCI 112
 * 1/20/17
 */

//Include standard libraries
#include <stdio.h>
#include <math.h>
//Define Constants
#define PI 3.14159
#define LOOP_LIMIT 90

//Delcare enum
enum MENU {sine, cosine, tangent, quit};
typedef enum MENU menu_t;
 
 //Declare Functions
int user_menu(void);
int valid_menu(const menu_t t);
void ex_sin(void);
void ex_cos(void);
void ex_tan(void);

//Main function
int main(void)
{
 int y = 0;//Prime do while loop
 
 do{//Do while loop for user input
 const t = user_menu();
 y = valid_menu(t);
 
 }while(y == 0);
 
}
//Function for displaying user menu
int user_menu(void)
{
 int a;
 printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
 printf("Enter your choice > ");
 scanf("%d", &a);
 return a;
}
//function to make sure menu has valid input and excute sin, cos, tan
int valid_menu(const menu_t t)
{
//Switch statement for enum 
 switch(t){
    case sine://Sine case
       ex_sin();//call to sine function
       return 0;
       break;

    case cosine://Cosine case
       ex_cos();//call to cosine function
       return 0;
       break;

    case tangent://Tangent case
       ex_tan();//Call to tangent function
       return 0;
       break;

    case quit://Quit the program
       printf("You chose QUIT. Thank you, come again!\n");
       return 1;
       break;

    default://Invalid option case
       printf("%d is an invalid option. PLease try again.\n", t);
       return 0;
       break;
 }
}

void ex_sin(void)
{
 for (int i = 0; i <= LOOP_LIMIT; i+=15)//Loop through all sine functions
 {
  double rad = (PI * (i/180.0));//convert to radians
  double num = sin(rad);//
  printf("\tsin(%d) = %.4lf\n", i, num);  
 }
}

void ex_cos(void)
{
 for (int i = 0; i <= LOOP_LIMIT; i+=15)//loop through all cosine functions
 {
  double rad = (PI * (i/180.0));//Convert to radians
  double num = cos(rad);
  printf("\tcos(%d) = %.4lf\n", i, num);
 }
}

void ex_tan(void)
{
 for (int i = 0; i <= LOOP_LIMIT; i+=15)//Loop through all tangent functions
 {
  if(i != 90)//if statement to handle tan(90)
  {
  double rad = (PI * (i/180.0));//Convert to radians
  double num = tan(rad);
  printf("\ttan(%d) = %.4lf\n", i, num);
  }
  else//else statement for when tan(90)
  {
   printf("\ttan(90) is UNDEFINED\n");
  } 
 }
} 
