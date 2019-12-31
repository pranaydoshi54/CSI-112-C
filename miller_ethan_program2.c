/* Miller, Ethan
 * Program 2, CSCI 112
 * 3/17/17
 */

//Include standard libraries
#include <stdio.h>

//Define constants
#define MAX_ARRAY_SIZE 50

//Define Function
int populate_array( int x[]); //Fill array with values from user
void print_array(int x[], int n); // Print out the array values
void swap( int x[], int index1, int index2); //Swap two array elements
void quicksort( int x[], int low, int high); // Sorting algorithm 
int partition( int x[], int low, int high); //Find the partition point (pivot)


//Main Function
int main(void)
{
 //Declare variables
 int n;
 int x[MAX_ARRAY_SIZE];

 n = populate_array(x); //Call to populate array
 
 printf("The initial array contains:\n");
 print_array(x, n); //Print out unsorted array
 quicksort(x, 0, n-1); //Sort array
 printf("The array is now sorted:\n");
 print_array(x, n); //Print out sorted array
 return 0;
}

//Populate Array Function
int populate_array(int x[])
{
 int n;
 do{ //Do while loop to make sure input is greater than 0 and less than 100
  printf("Enter the value of n > ");
  scanf("%d", &n);
  if(n > MAX_ARRAY_SIZE)
  {
   printf("%d exceeds the maximum array size. Please try again.\n\n", n);
  }
  if(n < 0)
  { 
   printf("%d is less than zero. Please try again.\n\n", n);
  }
 }while(n < 0 || n > MAX_ARRAY_SIZE);

 printf("Enter %d integers (positive, negative, or zero) >\n", n); 
 for (int i = 0; i < n; i++) // For loop to put each value into the array
 {
  int num;
  scanf("%d",&num);
  x[i] = num;
 }  
 return n;
}

//Print Function
void print_array(int x[], int n)
{
 for (int i = 0; i < n; i++)
 {
  printf("%+5d\n",x[i]); //Print statement with +5d to indent and print pos or neg
 }
}

//Swap Function
void swap(int x[], int index1, int index2)
{
 int temp = x[index1]; //Store x[index1] into a temporary variable
 x[index1] = x[index2];
 x[index2] = temp;
}

//Quicksort Function
void quicksort(int x[], int low, int high)
{
 if(low < high)
 {
  int pivot = partition(x, low, high); //Find the Pivot point
  quicksort(x, low, (pivot - 1)); //Quicksort 0 to pivot of array
  quicksort(x, (pivot + 1), high); //Quicsort top half of pivot to end of array
 }
}

//Partition Function
int partition(int x[], int low, int high)
{
 //Declare Variables
 int j;
 int pivot = x[high];
 int i = low;
 
 //For loop to shrink partition
 for (j = i; j <= high - 1; j++)
 {
  if(x[j] <= pivot)
  {
   swap(x, i, j);
   i += 1; 
  }
 }
 swap(x, i, high);
 return i;
} 
 
