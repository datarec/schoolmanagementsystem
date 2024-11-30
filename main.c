// school management system. 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


int studentLineIterations = 0; 
char test[3] = "763"; 


void checkRcNum(int rcGen) {
  FILE* rcFileA;
  FILE* rcFileR;  
  FILE* studentRc;
  rcFileR = fopen("studentrcs.txt", "r");
  if (rcFileR == NULL) {
    printf("\nFUCKK.");
    rcFileA = fopen("studentrcs.txt", "a");
    fprintf(rcFileA, "Student Rolecalls..\n");
  }
  rcFileA = fopen("studentrcs.txt", "a");
  studentRc = fopen("studentDB.txt", "a");
  char rcFileRead[20];
  char rcGenStr[10];

  while (fgets(rcFileRead, 20, rcFileR)) {
    rcFileRead[strcspn(rcFileRead, "\n")] = 0;
    sprintf(rcGenStr, "%d", rcGen);
    int compareRc = strcmp(rcGenStr, rcFileRead); 
    printf("\nreturnCode, %d", compareRc); // debug statement. 
    if (compareRc == 0) {
      printf("\nFatal error!");
      exit(1);
    }
    else {
      sprintf(rcGenStr, "%d", rcGen);   
      fprintf(rcFileA, "\n%s", rcGenStr);
      fprintf(studentRc, "\n\n", rcGenStr);
      break;
    }
  }
}


void generateRc() {
  int rC; 
	srand(time(0));
	for (rC= 0; rC < 1; rC++) {
		long int rcGen = (rand() % 1000000000) + 1;
    checkRcNum(rcGen);
  }
} 


void addStudent() {
  char studentFname[20];
  char studentLname[20];
  char studentDob[10];
  char submitData;
  printf("\nPlease enter the students information.\n\n");
  printf("First name (Name at birth) ");
  scanf("%s", &studentFname);
  printf("Student last name ");
  scanf("%s", &studentLname);
  printf("Student DOB (dd/mm/yyyy) ");
  scanf("%s", &studentDob);
  printf("\nWould you like to submit this? (y/n) ");
  scanf(" %c", &submitData);
  int nameLen = strlen(studentFname);
  int lnameLen = strlen(studentLname);
  int dobLen = strlen(studentDob);

  if (nameLen > 20) {
    printf("\n[!] This first name exceeds the character limit of 20.");
    exit(1);
  }
  else if (submitData == 'n') {
    printf("\nGoodbye.");
    exit(1);
  }
  else if (lnameLen > 20) {
    printf("\n[!] The last name of student %s exceeds the maximum character limit of 20.", studentFname);
    exit(1);
  }
  else if (dobLen > 10 || dobLen < 10) {
    printf("\n[!] Please ensure the date format is correct.");
    exit(1);
  }
  else if (submitData == 'y') {
    FILE* students;
    students = fopen("studentDB.txt", "a");
    generateRc();
    fprintf(students, "\nFIRST NAME: %s", studentFname);
    fprintf(students, "\nLAST NAME: %s", studentLname);
    fprintf(students, "\nD.O.B: %s", studentDob);
    printf("\n[!] Student successfully added! ");
    fclose(students);
  }
  else {
    exit(1);
  }
}


void searchStudent() {
  int searchOption;
  printf("Choose from the following; \n\n");
  printf("1) Search by Rolecall.");
  printf("\n2) Search by First Name\n");
  printf("\nSearch Option Selector (1,2) ");
  scanf("%d", &searchOption);
  if (searchOption == 1) {
    printf("hio");
  }
}


void getStudentCount() {
  FILE* gsCount;
  gsCount = fopen("studentDB.txt", "r");
  char gsCountData[50];
  while (fgets(gsCountData, 50, gsCount)) {
    studentLineIterations++;
  }
}


 
void smsMain() {
  int smsMainOption;
  getStudentCount();
  int studentCount = (studentLineIterations - 1) / 4;
  printf("\nSchool Student Management System (SSMS)");
  printf("\nStudents enrolled: %d", studentCount);
  printf("\n\n1) Add a student");
  printf("\n2) Search student (ADD MORE OPTIONS. using role-call number)");
  printf("\n\n>> ");
  scanf("%d", &smsMainOption); 
  if (smsMainOption == 1) {
    addStudent();
  } 
  else if (smsMainOption == 2) {
    searchStudent();
  }
}


int main() {
  smsMain();
}
