/*
 * Miller, Ethan
 * Program 3, CSCI 112
 * 4/17/17
 */

//Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Define Constants
#define NAME_SIZE 25

//Define student structure
typedef struct{
 int sid;
 char lName[NAME_SIZE];
 char fName[NAME_SIZE];
 float * gradeList;
 float gpa;
  }student;

//Declare Functions
student stud_input(int y);
float calc_gpa(student a, int y);
void print_studRecords(student * s, int x, int y);
void free_memory(student * s, int x);

int main(int argc, char * argv[])
{
 int studentNum;
 int gradeNum;
 scanf("%d", &studentNum);//Prompt user for number of students
 scanf("%d", &gradeNum);//Prompt user for number of grades
 printf("Number of students: %d\n", studentNum);
 printf("Number of grades (each): %d\n", gradeNum);
 
 student * students = (student *) calloc(studentNum, sizeof(student));//Declare memory for student list
 
 for (int i = 0; i < studentNum; i++)//For loop to input number of students 
 {
  *(students + i) = stud_input(gradeNum);
 }

 print_studRecords(students, studentNum, gradeNum);//Call to print all students in studnet list
 free_memory(students, studentNum);//Call to free memory
 return 0;
}

//Function for adding student to list
student stud_input(int y)
{
 student s1;
 scanf("%d", &(s1.sid));//Prompt user for student id
 scanf("%s", s1.lName);//Prompt user for last name
 scanf("%s", s1.fName);//Prompt user for first name

 s1.gradeList = (float *) calloc(y, sizeof(s1.gradeList));//Declare memory for gradelist pointer for students

 for(int i = 0; i < y; i++)//For loop to prompt user for grades
 {
  scanf("%f", &s1.gradeList[i]);
 }
 s1.gpa = calc_gpa(s1, y);//Call helper calc gpa function
 return s1;
} 

//Function to calculate GPA 
float calc_gpa(student a, int y)
{ 
 float sum;
 float avg;
 for(int i = 0; i < y; i++)//For loop to sum all grades
 {
  sum = sum + a.gradeList[i];
 }
 avg = sum / y;
 return avg;
}

//Function to print a student
void print_studRecords(student * s, int x, int y)
{
 for(int i = 0; i < x; i++)//For loop to print each student in student list
 {
  printf("ID: %d, ", (s + i)->sid);
  printf("Name: %s ", (s + i)->fName);
  printf("%s, ", (s + i)->lName);
  printf("GPA: %.2f\n", (s + i)->gpa);
  printf("Grades: ");
  for(int j = 0; j < y; j++)//For loop to print each grade in each student in student list
  {
   printf("%.1f ", (s + i)->gradeList[j]);
  }
  printf("\n");
 }
}

//Function to free memory 
void free_memory(student * s, int x)
{
 for(int i = 0; i < x; i++)//For loop to free gradeList for each student
 {
  free(s[i].gradeList);
  s[i].gradeList = NULL;
 }
 free(s);//Free list of students
 s = NULL;
}
