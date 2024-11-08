// school management system. 

#include <stdio.h>
#include <stdlib.h>

void addStudent() {
  char studentFname;
  char studentLname;
  char studentDob;
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
  if (submitData == 'y') {
    printf("\nStudents name: %s", studentFname);
    FILE* students;
    students = fopen("studentDB.txt", "a");
    fprintf(students, studentFname);
    fclose(students);
  } 
  else {
    exit(1);
  }
}


void searchStudent() {
  printf("Search student.");
}


void smsMain() {
  int smsMainOption;
  printf("Welcome to the school's Student Management System.");
  printf("\nStudents enrolled: 0");
  printf("\n\n1) Add a student");
  printf("\n2) Search student (ADD MORE OPTIONS. using role-call number)");
  printf("\n\n[>] ");
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
