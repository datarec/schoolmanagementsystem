// school management system. 

#include <stdio.h>

 struct student {
    char studentFname;
    char studentLname;

  };


void addStudent() {
  // add students function.
  struct student {
    char studentFname;
    char studentLname;
    char studentDob;
    char submitData;
  };
  
  struct student studentInfo; 
  FILE* students;
  printf("\nPlease enter the students information.\n\n");
  printf("First name (Name at birth) ");
  scanf("%s", &studentInfo.studentFname);
  printf("Student last name ");
  scanf("%s", &studentInfo.studentLname);
  printf("Student DOB (dd/mm/yyyy) ");
  scanf("%s", &studentInfo.studentDob);
  printf("\n\nWould you like to submit this? (y/n) ");
  scanf("%c", &studentInfo.submitData);
  if (studentInfo.submitData == 'y') {
    students = fopen("students.txt", "a");
    fprintf("%c", studentInfo.studentFname);
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
