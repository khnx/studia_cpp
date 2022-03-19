#ifndef MIXER_H
#define MIXER_H

#include <iostream>
#include <cstring>
#include <array>

typedef std::array<int, 2> statArr2;

class Mixer {

private:
  bool is_on;                     // Is the device turned on or off.
  bool is_mixing;                 // Is mixing initiated.
  bool is_mixing_stopped;         // Is mixing stopped.
  bool is_cover_closed;           // The device cover.
  int time;                       // How long does mixing last for.
  statArr2 time_range;            // Min (arg [0])/ max (arg [1]) time value.
  int temp;                       // Temperature.
  statArr2 temp_range;            // Min (arg [0])/ max (arg [1]) temp value.
  int rpm;                        // Rotation per minute.
  statArr2 rpm_range;             // Min (arg [0])/ max (arg [1]) rpm value.
  bool is_cleaning;               // Should the inside of the mixer be cleaned.
  bool is_flushing;               // Should the inside of the mixer be flushed.

public:
  Mixer();
  Mixer(
    bool on, bool mixing, bool mixinig_stopped, bool cover_closed,
    int t, statArr2 t_range, int temperature, statArr2 temperature_range,
    int rotation, statArr2 rotation_range, bool cleaning, bool flushing
  );

  bool on_off_switch();           // Turn the device on/ off.
  bool start();                   // Turn the mixing on.
  bool end();                     // End the mixing.
  bool stop();                    // Stop the mixing.
  bool resume();                  // Continue previously stopped mixing.
  bool abort();                   // Abort the mixing.
  bool switch_cover(std::string);// Close/ open the cover.
  int set_time(int t);            // Set the time for which mixing continues.
  int time_up();                  // Increase time by 1.
  int time_down();                // Decrease time by 1.
  int set_temp(int t);            // Set the temperature.
  int temp_up();                  // Increase time by 1.
  int temp_down();                // Decrease time by 1.
  int rpm_up();                   // Increase the rotation by 1.
  int rpm_down();                 // Decrease the rotation by 1.
  int set_rpm(int);               // Select rpm;
  bool flush();                   // Flush the contents of the mixer.
  bool flush_end();               // End flushing.
  bool clean();                   // Clean the inside of the mixer.
  bool clean_end();               // End cleaning.
  void log_state();               // Log the state of the class' private parts.

};

#endif    // MIXER_H