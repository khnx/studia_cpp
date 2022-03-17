#include <cstdlib>
#include <iostream>

#include "classes/PersonClass.h"

int main() {

  PersonClass Person_1("Jan", "Kowalski", 40);

  char name[32]{};
  char last_name[32]{};
  int age = 5;

  std::cout << "Enter data of the first Person: ";

  std::cout << "\nName: ";
  std::cin.getline(name, sizeof(name));
  
  std::cout << "Last name: ";
  std::cin.getline(last_name, sizeof(last_name));
  
  std::cout << "Age: ";
  std::cin >> age;

  Person_1.f_read(name, last_name, age);
  Person_1.f_write();

  exit(EXIT_SUCCESS);
}