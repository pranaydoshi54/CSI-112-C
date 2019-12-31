/*
 * Miller, Ethan 
 * Lab 5, CSCI 112
 * 2/26/17
 */

//Include standard libraries
#include <stdio.h>

//Define constant for size of array
#define BARCODESIZE 12

//Define functions
int calc_oddSumT3(int x[]);
int calc_evenSum(int x[]);
int calc_sum(int x, int y);
int calc_checkDigit(int z);
int check_valid(int x[], int a);
void valid_barcode(int x);

//Main function
int main(void)
{
 int barcode[BARCODESIZE];//Initialize array
 printf("Enter a bar code to check. Seperate digits with a space >\n");
 for (int i = 0; i < 12; i++)//For loop to put elements in array with user input
 {
  scanf("%d",(barcode + i));
 }
 printf("\nYou have entered the code: ");
 for (int i = 0; i < BARCODESIZE; i++)//For loop to print out user input
 {
  printf("%d ", barcode[i]);
 }

 int x = calc_oddSumT3(barcode);//Function call to calculate odd sum times 3
 int y = calc_evenSum(barcode);//Function call to calculate even sum
 int z = calc_sum(x, y);//Function call to calculate these two sums
 int checkDigit = calc_checkDigit(z);//Function call to get check digit
 int valid = check_valid(barcode, checkDigit);//Function call to see if check digits match
 valid_barcode(valid);//Function call to print out whether or ot barcode is valid
} 

//Function to calc odd sum times 3
int calc_oddSumT3(int x[])
{
 int sum = 0;
 for (int i = 0; i < BARCODESIZE; i+=2)//For loop to add all odd postions in barcode
 {
   sum = sum + x[i];
 }
 sum = sum * 3;//Multiply sum of all odd elements by 3
 printf("\nSTEP 1: Sum of odd times 3 is %d\n", sum);
 return sum; 
}

//Function to calc even sum
int calc_evenSum(int x[])
{
 int sum = 0;
 for (int i = 1; i < 11; i+=2)//For loop to add all even positions in barcode
 {
  sum = sum + x[i];
 }
 printf("STEP 2: Sum of the even digits is %d\n", sum);
 return sum;
}

//Function to calc sum for check digit
int calc_sum(int x, int y)
{
 int sum = x + y;//Adds even sum and odd sum times 3 together
 printf("STEP 3: Total sum is %d\n", sum);
 return sum;
}

//Function to calc check digit
int calc_checkDigit(int z)
{
 int checkDigit = z % 10;//Gets last digit from 10
 checkDigit = 10 - checkDigit;
 printf("STEP 4: Calculated check digit is %d\n", checkDigit);
 return checkDigit;
}
//Function to check if barcode is valid or invalid
int check_valid(int x[], int a)
{ 
 if (x[11] == a)
 {
  printf("STEP 5: Check digit and last digit match\n");
  return 1;
 }
 else
 {
  printf("STEP 5: Check digit and last digit do not match\n");
  return 0;
 }
}

//Function to print out if barcode is vlid or invalid
void valid_barcode(int x)
{
  if(x == 1)
 {
  printf("Barcode is VALID\n\n");
 }
 else
 {
  printf("Barcode is INVALID\n\n");
 }
}
