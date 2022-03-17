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

void PersonClass::f_read(const char *n, const char *l_name, int a) {
  
  strncpy(name, n, MAXLINE);
  strncpy(last_name, l_name, MAXLINE);
  age = a;
}
