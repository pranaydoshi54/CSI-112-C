/* Miller, Ethan 
 * lab 8, CSCI 112
 * 3/29/17
 */


//Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Define constant
#define SIZE 80

//Define functions
void reverseWords(char *String);
void reverse(char *begin, char *end);


//Main Function
int main(int argc, char *argv[])
{
 if(argc != 2)
 {
  printf("ERROR: Please provide an integer greater than or equal to 0\n");
  return 0;
 } 

 int N = (int) strtol(argv[1], NULL, 10);
 if(N < 0)
 {
  printf("ERROR: Please provide an integer greater than or equal to 0\n");
  return 0;
 }

 char line[SIZE]; 
 while(fgets(line, SIZE, stdin ) && N > 0)//Command Line
 {
   reverseWords(line);
   printf("%s\n", line);
   N--;
 }
  return 0;
}

//Method to reverse 
void reverse(char *start, char *end)
{
  char temp;
  while (start < end)
  {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

//reverseWords function
void reverseWords(char *String)
{
  char *word_start = String;
  char *temp = String; 
 
  //While loop for all the words
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_start, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_start, temp-1);
      word_start = temp+1;
    }
  } //End of while loop
 
  reverse(String, temp-1);
}
