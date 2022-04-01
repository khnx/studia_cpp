#include "PersonClass.h"

#define MAXLINE 32

PersonClass::PersonClass() {

  strncpy(name, "", MAXLINE);
  strncpy(last_name, "", MAXLINE);
  age = 0;
}

PersonClass::PersonClass(const char *n, const char *l_name, int a) {

  strncpy(name, n, MAXLINE);
  strncpy(last_name, l_name, MAXLINE);
  age = 0;
}

PersonClass::~PersonClass() {

}

void PersonClass::f_read(const char *n, const char *l_name, int a) {
  
  strncpy(name, n, MAXLINE);
  strncpy(last_name, l_name, MAXLINE);
  age = a;
}

void PersonClass::f_write() {
    std::cout << name << " " <<
    last_name << " " << age << std::endl; 
  }

void PersonClass::f_write() {
  std::cout << name << " " <<
  last_name << " " << age << std::endl; 
}


LecturerClass::LecturerClass() {
  years_of_work = 0;
}

LecturerClass::LecturerClass(const char *i, const char *n, int w, int sp) {
  PersonClass(i, n, w);
  
  years_of_work = sp;
}

LecturerClass::~LecturerClass() {

}

void f_write_data(PersonClass Person) {
  std::cout << Person.name << std::endl;
}