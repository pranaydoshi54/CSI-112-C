/* Miller, Ethan 
 * Lab 7, CSCI 112
 * 3/24/17
 */

//Include Standard Libraries
#include <stdio.h>
#include <string.h>

//Function Prototypes
char *my_strncpy(char *dest, char *source, int n);
char *my_strncat(char *dest, char *source, int n);

//Homegrown strncpy function
char *my_strncpy(char *dest, char *source, int n)
{
 for (int i = 0; i < n; i++) //For loop to assign values in source to values in dest
 {
  dest[i] = source[i];
 }
 dest[n] = '\0';//Add null character in appropriate place
 return dest;
}

//Homegrown strncat function
char *my_strncat(char *dest, char *source, int n)
{
 char *rdest = dest;
 while(*dest)
 {
  dest++;
 }
 while (*dest++ = *source++)
 {
  ;
 }
 return rdest;
}

//Main function
int main(void)
{
 //Declare test arrays
 char testSrc[] = "Hello";
 char testDest[40] = "world";
 int n = 5;

 //call to homegrown strncat
 my_strncat(testDest, testSrc, n);
 printf("CAT: %s \n", testDest);
 
 //Call to homegrown strncpy
 my_strncpy(testDest, testSrc, n);
 printf("CPY: %s \n", testDest);

 printf("%s \n", testDest);
 return 0; //Return with no errors
}

