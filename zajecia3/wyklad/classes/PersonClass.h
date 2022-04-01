#pragma once

#ifndef PERSON_CLASS_H
#define PERSON_CLASS_H

#include <iostream>
#include <cstring>

class PersonClass {     // Class definition.
  
protected:
  char name[32];        // Private part.
  char last_name[32];
  int age;

public:                 // Public part.

  PersonClass();
  PersonClass(const char *name, const char *last_name, int age);
  ~PersonClass();
  
  void f_read(const char *name, const char *last_name, int age);
  void f_write();

  friend void f_write_data(PersonClass Person);

};

#endif

class LecturerClass {

private:
  int years_of_work;

public:
  LecturerClass();
  LecturerClass(const char *i, const char *n, int w, int sp);
  ~LecturerClass();

  void f_write_data(PersonClass Person);
};