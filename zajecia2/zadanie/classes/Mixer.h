#ifndef MIXER_H
#define MIXER_H

#include <iostream>
#include <array>

class Mixer {

private:
  bool is_on;                     // Is the device turned on or off.
  bool is_mixing;                 // Is mixing initiated.
  bool is_mixing_stopped;         // Is mixing stopped.
  bool is_cover_closed;           // The device cover.
  int time;                       // How long does mixing last for.
  int rpm;                        // Rotation per minute.
  std::array<int, 2> rpm_range;   // Min (arg [0])/ max (arg [1]) rpm value.
  bool is_clean;                  // Should the inside of the mixer be cleaned.
  bool is_flush;                  // Should the inside of the mixer be flushed.

public:
  bool on_off_switch();           // Turn the device on/ off.
  bool start();                   // Turn the mixing on.
  bool stop();                    // Stop the mixing.
  bool resume();                  // Continue previously stopped mixing.
  bool abort();                   // Abort the mixing.
  bool switch_cover();            // Close/ open the cover.
  int set_time(int t);            // Set the time for which mixing continues.
  int rpm_up();                   // Increase the rotation by 1.
  int rpm_down();                 // Decrease the rotation by 1.
  int rpm_select(int rotation);   // Select rpm;
  bool flush(bool destination);   // Flush the contents of the mixer.
  bool clean();                   // Clean the inside of the mixer.
  void log_state();               // Log the state of the class' private parts.

};

#endif    // MIXER_H