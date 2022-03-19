#include <iostream>
#include <cstdlib>

#include "classes/Mixer.h"

int main() {
  
  Mixer TheMixer{};

  TheMixer.log_state();

  exit(EXIT_SUCCESS);
}