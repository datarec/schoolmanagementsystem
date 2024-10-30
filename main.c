// school management system. 

#include <stdio.h>


void addStudent() {
  printf("In student");
}


void searchStudent() {
  printf("In search");
}


void smsMain() {
  int smsMainOption;
  printf("Welcome to the school's Student Management System.");
  printf("\n\n1) Add a student");
  printf("\n2) Search student (using role-call number)");
  printf("\n\n>> ");
  scanf("%d", smsMainOption); 
  printf("UI chjeck from thingp. /%d", smsMainOption);
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
