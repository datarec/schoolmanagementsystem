// school management system. 



// fix first student not going to the next line (goes on line 1234.)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


int studentLineIterations = 0; 
char test[5] = "7362"; // DEBUG STATEMENT


void checkRcNum(int rcGen) {
  FILE* rcFileA;
  FILE* rcFileR;
  FILE* studentRc;
  rcFileR = fopen("studentRcs.txt", "r");
  rcFileA = fopen("studentRcs.txt", "a");
  studentRc = fopen("studentDb.txt", "a");
  char rcFileRead[10];
  char rcGenStr[10];

  while (fgets(rcFileRead, 10, rcFileR)) {
    rcFileRead[strcspn(rcFileRead, "\n")] = 0;
    sprintf(rcGenStr, "%d", rcGen);
    int compareRc = strcmp(rcGenStr, rcFileRead); 
    if (compareRc == 0) {
      printf("\nFatal error!");
      exit(1);
    }
  }
  fprintf(rcFileA,"%s\n", rcGenStr);
  fprintf(studentRc, "\nStudent RC Number: %s", rcGenStr);
  fclose(rcFileA);
  fclose(rcFileR);
  fclose(studentRc);
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
  char studentLastName[20];
  char studentDob[11];
  char submitData;
  printf("\nPlease enter the students information.\n\n");
  printf("First name (Name at birth) ");
  scanf("%s", &studentFname);
  printf("Last name ");
  scanf("%s", &studentLastName);
  printf("Student DOB (dd/mm/yyyy) ");
  scanf("%s", &studentDob);
  printf("\nWould you like to submit this? (y/n) ");
  scanf(" %c", &submitData);

  int nameLen = strlen(studentFname);
  int lnameLen = strlen(studentLastName);
  int dobLen = strlen(studentDob);

  if (nameLen > 20) {
    printf("\n[!] This first name exceeds the character limit of 20. Please retry.");
    exit(1);
  }
  else if (nameLen < 1) {
    printf("\n[!] This first name is too shoot. Please retry.");
    exit(1);
  }
  else if (submitData == 'n') {
    printf("\nDATA DUMPED.");
    printf("\nExiting...");
    exit(1);
  }
  else if (lnameLen > 20) {
    printf("\n[!] The last name of student %s exceeds the maximum character limit of 20. Please retry.", studentFname);
    exit(1);
  }
  else if (lnameLen < 1) {
    printf("\nThis last name cannot be shorter than 1 character. Please retry");
    exit(1);
  }
  else if (dobLen > 10 || dobLen < 10) {
    printf("\n[!] Please ensure the date format is correct. Please retry.");
    exit(1);
  }
  else if (submitData == 'y') {
    FILE* students;
    students = fopen("studentDb.txt", "a");
    generateRc();
    fprintf(students, "\nFIRST NAME: %s", studentFname);
    fprintf(students, "\nLAST NAME: %s", studentLastName);
    fprintf(students, "\nD.O.B: %s\n", studentDob);
    printf("\n[!] Student successfully added! \n");
    fclose(students);
  }
  else {
    exit(1);
  }
}

int rcitercount = 0;

void searchRolecall() {
  FILE* searchRolecall;
  char rcEntry[20];
  printf("\nEnter rolecall no: ");
  scanf("%s", &rcEntry);
  printf("\nout of function %s", rcEntry);
  searchRolecall = fopen("studentRcs.txt", "r");
  char rcs[20];
  while (fgets(rcs, 20, searchRolecall)) {
    rcs[strcspn(rcs, "\n")] = 0;
    printf("%s", rcs);
    int rcECompare = strcmp(rcEntry, rcs);
    if (rcECompare == 0) {
      printf("\n\nYozaaa"); // DEBUG IF STATEMENT
      exit(1);
    }
    printf("\n\nRC-CHECK %d", rcECompare); // DEBUG STATEMENT.
    printf("\nrcitercount %d", rcitercount); // DEBUG STATEMENT.
    printf("\nRC Entry: %s", rcEntry); // DEBUG STATEMENT. 
    printf("\nRC No: %s", rcs); // DEBUG STATEMENT.
    rcitercount = rcitercount + 1;
  }
}


void searchLastName() {
  int pass;
}


void searchStudent() {
  int searchOption;
  printf("\nChoose from the following; \n\n");
  printf("1) Search by Rolecall.");
  printf("\n2) Search by First Name\n");
  printf("\nSearch Option Selector (1,2) ");
  scanf("%d", &searchOption);
  if (searchOption == 1) {
    searchRolecall();
  }
  else if (searchOption == 2) {
    searchLastName();
  }
}


void getStudentCount() {
  FILE* gsCount;
  gsCount = fopen("studentDb.txt", "r");
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
  FILE* checkRcExist;
  FILE* checkStudentDBExist;
  checkRcExist = fopen("studentRcs.txt", "r");
  checkStudentDBExist = fopen("studentDb.txt", "r");
  if (checkRcExist == NULL && checkStudentDBExist == NULL) {
    FILE* checkRcExistW;
    FILE* checkStudentDBExistW;
    checkRcExistW = fopen("studentRcs.txt", "a");
    checkStudentDBExist = fopen("studentDb.txt", "a");
    fprintf(checkRcExistW, "1234\n\n");
    printf("[!] Initializing Database. please retry.\n[!] Complete!\n[!] Please retry.");
    exit(1);
  }
  else {
    smsMain();
  }
}

