/* Miller, Ethan 
 * lab 9, CSCI 112
 * 4/10/17
 */

//Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Define Constant
#define MAX_ELEMENTS 20


//Define Structure for elements
typedef struct{
	int atomicNum;
	char name[25];
	char chemSym[4];
	char class[10];
	double atomWeight;
	int electronNum[25];
       }element_t;	

//Define Functions
element_t scan_element(void);
void print_element(element_t x);

//Main Function
int main(int argc, char * argv[])
{
 element_t e[MAX_ELEMENTS];//Declare element array

 if(argc < 2)//If statement no argument 
 {
  printf("ERROR: You must provide exactly one argument to this program\n");
  return 0;
 } 
 int N = (int) strtol(argv[1], NULL, 10);
 if(N <= 0 || N > MAX_ELEMENTS)//If statement for argument less than 0 or greater than 20
 {
  printf("ERROR: Please provide an integer greater than 0 and less than or equal to 20.\n");
  return 0;
 }
 else	
 {
  for (int i = 0; i < N; i++)//For loop for scanning in number of elements in command line argument
  {
   e[i] = scan_element();
  }
  printf("%d total elements.\n", N);//Print total number of elements
  
  element_t min = e[0];//Set min to first element
  element_t max = e[0];//Set max to first element

  for (int i = 1; i < N; i++)//For loop for finding element with min atomic num
  {
   if(e[i].atomicNum < min.atomicNum)
   {
    min = e[i];
   } 
  } 
  printf("%s had the smallest atomic number.\n", min.name);//Print element with min atomic num
  
  for(int i = 1; i < N; i++)//For loop for finding element with max atomic num
  {
   if(e[i].atomicNum > max.atomicNum)
   {
    max = e[i];
   }
  }
  printf("%s had the largest atomic number.\n", max.name);//Print element with max atomic num

  for(int i = 0; i < N; i++)//For loop for printing out all elements in element array
  {
   print_element(e[i]);
  }
  return 0;
 }
}

//Scan element function
element_t  scan_element(void)
{
 element_t  e1;
 scanf("%d %s %s %s %lf", &(e1.atomicNum), e1.name, e1.chemSym, e1.class, &(e1.atomWeight));
 for (int i = 0; i < 7; i++)//For loop to scan in electron shell
 {
  scanf("%d", &e1.electronNum[i]);
 }
 return e1; 
}

//Print element function
void print_element(element_t x)
{
 printf("---------------\n");
 printf("| %d\t %.4lf\n",x.atomicNum, x.atomWeight);
 printf("| %s\t %s\n", x.chemSym, x.name);
 printf("| ");
 for (int i = 0; i < 7; i++)//For loop to print electron shell
 {
  if(x.electronNum[i] != 0)//If statement to leave zeros out
  {
   printf("%d ", x.electronNum[i]);
  }
 }
 printf("\n---------------\n");
}
