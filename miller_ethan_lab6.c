/*
 * Miller, Ethan 
 * Lab 5, CSCI 112
 * 3/6/17
 */

//Include standard libraries
#include <stdio.h>
#include <math.h>

//Define functions

//Displays iser menu, reads input, and validates input
int user_menu(void);

//Equation functions that are pass by reference
void equation1(float *y);
void equation2(float *y);
void equation3(float *y);
void equation4(float *y);

//User input functions return a value from user
float get_position_inital(void); //Prompts user for x0
float get_position_final(void); //Prompts user for xf
float get_velocity_intial(void); //Prompts user for v0
float get_velocity_final(void); //Prompts user for vf
float get_acceleration(void); //Prompts user fpr a
float get_time(void); //Prompts user for t

int main(void)
{
 // Print welcome message
 printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");

 //Variable for the user choice menu.
 int user_choice;

 do
 {
    user_choice = user_menu(); // print menu, validate choice is between 1 and 5 
    //pass the address of this variable to equation functions
    float result;

    //Handle menu choice selected by user
    switch ( user_choice )
    {
      case 1: //Case for equation 1
         equation1(&result);
         break;

      case 2: //Case for equation 2
         equation2(&result);
         break;

      case 3: //Case for equation 3
         equation3(&result);
         break;
    
      case 4: //Case for equation 4
         equation4(&result);
         break;
 
      case 5: //Exit program if user selects quit
         printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
         return 0;
         break;
    
      default:
         break;
    }

    //Print out the calculated result with four digits after the decimal place
    if(user_choice > 0 && user_choice <= 5)
    {
     printf("Your result is %.4f.\n\n", result);
    }
    else
    {
     printf("Invalid Option. Please try again.\n\n");
    }
   }while (user_choice != 5 );

   return 0; //Exit with no error
}

//Function to display user menu
int user_menu(void)
{ 
 int x;
 printf("Choose a motion equation 1-4 or choose 5 to quit > ");
 scanf("%d", &x);
 return x;
}

//Function to get x0
float get_position_initial(void)
{
 float x;
 printf("\tEnter initial Position > ");
 scanf("%f", &x);
 return x;
}

//Function to get xf
float get_position_final(void)
{
 float x;
 printf("\tEnter final position > ");
 scanf("%f", &x);
 return x;
}

//Function to get v0
float get_velocity_initial(void)
{
 float x;
 printf("\tEnter initial velocity > ");
 scanf("%f", &x);
 return x;
}

//Function to get vf
float get_velocity_final(void)
{
 float x;
 printf("\tEnter final velocity > ");
 scanf("%f", &x);
 return x;
}

//Function to get a
float get_acceleration(void)
{
 float x;
 printf("\tEnter acceleration > ");
 scanf("%f", &x);
 return x;
}

//Function to get t
float get_time(void)
{
 float x;
 printf("\tEnter time > ");
 scanf("%f", &x);
 return x;
}

//Motion equation 1
void equation1(float *y)
{
 float v0 = get_velocity_initial();
 float a = get_acceleration();
 float t = get_time();
 *y = v0 + (a * t);
}

//Motion equation 2
void equation2(float *y)
{
 float x0 = get_position_initial();
 float v0 = get_velocity_initial();
 float t = get_time();
 float a = get_acceleration();
 *y = x0 + v0 * t + (0.5 * a * pow(t, 2));
}

//Motion equation 3
void equation3(float *y)
{
 float v0 = get_velocity_initial();
 float a = get_acceleration();
 float xf = get_position_final();
 float x0 = get_position_initial();
 *y = sqrt(pow(v0, 2) + 2 * a * (xf - x0));
}

//Motion equation 4
void equation4(float *y)
{
 float x0 = get_position_initial();
 float vf = get_velocity_final();
 float v0 = get_velocity_initial();
 float t = get_time();
 *y = x0 + 0.5 * (vf + v0) * t;
}
