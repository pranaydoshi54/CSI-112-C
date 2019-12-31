/*
 * Miller, Ethan
 * Lab 10, CSCI 112
 * 4/20/17
 */

//Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Constansts
#define ELEMENT_FILENAME "element_db.csv"

//Define element structure
typedef struct{
	int atomic_number;
	char symbol[4];
	char name[25];
	float atomic_weight;
	char state[25];
	char bonding_type[25];
	char discovered[25];
}element_t;

//Define function prototypes
element_t * find_element(element_t * list, char * symbol);

//Main Function
int main(int argc, char * argv[])
{
 if(argc < 2)
 {
  printf("ERROR: Please provide at least one program argument.\n");
  return 0;
 }
 
 element_t * elements = (element_t *)calloc(118, sizeof(element_t));

 FILE * element_file = fopen(ELEMENT_FILENAME, "r");
 if(element_file != NULL)
 {
  char line[100];
  while(fgets(line, 100, element_file) != NULL)
  {
   //Remove newline character from line
   char * n1 = strchr(line, '\n');
   if(n1)
   {
    *n1 = '\0';
   }

   element_t e;
   char * str = strtok(line, ",");
   int col = 0;
   while(str != NULL)//Check to make sure strin isnt NULL
   {
    switch(col)//Switch to scan in each section of input 
    {
     case 0:
  	 e.atomic_number = atoi(str);
	 break;
     case 1:
         strcpy(e.symbol, str);
	 break;
     case 2:
	 strcpy(e.name, str);
         break;
     case 3:
         e.atomic_weight = atof(str);
	 break;
     case 4:
	 strcpy(e.state, str);
 	 break;
     case 5:
	 strcpy(e.bonding_type, str);
 	 break;
     case 6:
	 strcpy(e.discovered, str);
         break;

         
    }
    str = strtok(NULL, ",");
    col++;
   }
   elements[e.atomic_number - 1] = e;
  }
  fclose(element_file);
 }
 
 //Process program arguments
 FILE * output_f = NULL;
 int i;
 char * dot;
 for(i = 1; i < argc; i++)//For loop to scan user input
 {
  if(i == 1)//Check for filename
  {
   dot = strchr(argv[i], '.');

   if(dot)//If a filename is inputted
   {
    output_f = fopen(argv[i], "w");
    element_t * ele = find_element(elements, argv[i]);

    if(ele)//If element exists
    {
     fprintf(output_f, "---------------\n");
     fprintf(output_f, "|%d\t%.4f\n", ele->atomic_number, ele->atomic_weight);
     fprintf(output_f, "|%s\t%s\n", ele->symbol,ele->name);
     fprintf(output_f, "|%s\n", ele->state);
     fprintf(output_f, "|%s\n",ele->bonding_type);
     fprintf(output_f, "|Found: %s\n",ele->discovered);
     fprintf(output_f, "---------------\n");
    }
    continue;
   }
  }

  //No filename inputted
  if(dot == NULL)
  {
   element_t * ele = find_element(elements, argv[i]);
   if(ele)//If element exists
   {
    printf("---------------\n");
    printf("|%d\t%.4f\n", ele->atomic_number, ele->atomic_weight);
    printf("|%s\t%s\n", ele->symbol,ele->name);
    printf("|%s\n", ele->state);
    printf("|%s\n",ele->bonding_type);
    printf("|Found: %s\n",ele->discovered);
    printf("---------------\n");
   }
   else//If element does not exist
   {
    printf("Warning: No such element: %s\n", argv[i]);
   }
  }
 }
  return 0;
}

//Find element function
element_t * find_element(element_t * list, char * symbol)
{
 int i;
 for(i = 0; i < 118; i++)
 {
  if(strcmp(list[i].symbol, symbol) == 0)
  {
   element_t * result = &list[i];
   return result;
  }
 }
 return NULL;
}

 
