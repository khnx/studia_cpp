#include <cstdlib>
#include <iostream>

#include "classes/PersonClass.h"

int main() {

  LecturerClass *obj1 = new LecturerClass();

  obj1 -> f_write_data();

  exit(EXIT_SUCCESS);
}