#pragma once

#ifndef PERSON_CLASS_H
#define PERSON_CLASS_H

#include <iostream>
#include <cstring>

class PersonClass {     // Class definition.
  
  char name[32];        // Private part.
  char last_name[32];
  int age;

public:                 // Public part.

  PersonClass();
  PersonClass(const char *name, const char *last_name, int age);
  
  void f_read(const char *name, const char *last_name, int age);
  void f_write() {
    std::cout << name << " " <<
    last_name << " " << age << std::endl; 
  }

};

#endif