#include "class/Nanobot.h"
#include <cstdlib>
#include <iostream>

int main() {

  Nanobot bot1;
  bot1.set_position(6, -45);
  bot1.set_radiation();
  bot1.set_radiation();
  bot1.set_radiation();
  bot1.set_radiation();
  bot1.reset_radiation_count();
  bot1.set_radiation();
  bot1.set_radiation_sample_interval(0.5);
  bot1.set_radiation();
  bot1.set_radiation();

  bot1.set_frequency(0);

  bot1.log_state_obj();

  array<Nanobot, 5> Bots;

  for (size_t i = 0; i < Bots.size(); i++) {
    Bots[i].set_radiation();
    Bots[i].set_radiation();
    Bots[i].set_frequency(100 * i + 3e4);
    Bots[i].set_radiation();
    Bots[i].set_position(i);
  }

  Bots[3].set_position(20, 445);

  bot1.find_nearest_relative();
  Nanobot::log_state();

  exit(EXIT_SUCCESS);
}