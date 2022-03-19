#include "Mixer.h"

Mixer::Mixer() {
  is_on = false;
  is_mixing = false;
  is_mixing_stopped = false;
  is_cover_closed = false;
  time = 180;    // Sec.
  time_range = { 0, 500 };
  temp = 28;    // Deg C.
  temp_range = { 14, 74 };
  rpm = 60;
  rpm_range = { 30, 300 };
  is_cleaning = false;
  is_flushing = false;
}

Mixer::Mixer(
  bool on, bool mixing, bool mixinig_stopped, bool cover_closed,
  int t, statArr2 t_range, int temperature, statArr2 temperature_range,
  int rotation, statArr2 rotation_range, bool cleaning, bool flushing
  ) {
  is_on = on;
  is_mixing = mixing;
  is_mixing_stopped = mixinig_stopped;
  is_cover_closed = cover_closed;
  time = t;    // Sec.
  time_range = t_range;
  temp = temperature;    // Deg C.
  temp_range = temperature_range;
  rpm = rotation;
  rpm_range = rotation_range;
  is_cleaning = cleaning;
  is_flushing = flushing;
}

bool Mixer::on_off_switch() {
  // Interference with another action.
  if (is_mixing || is_mixing_stopped || is_cleaning || is_flushing)
    return false;
  
  if (is_on) {
    is_on = false;
    return true;
  }
  is_on = true;
  return true; 
}

bool Mixer::start() {
  // Can't start mixing.
  if( !is_on || is_mixing || is_mixing_stopped || !is_cover_closed)
    return false;
  // Start mixing.
  is_mixing = true;
  return true;
}

bool Mixer::end() {
  if( !is_on || is_mixing_stopped)
    return false;
  is_mixing = false;
  return true;
}

bool Mixer::stop() {
  if (is_on && is_mixing && !is_mixing_stopped) {
    is_mixing_stopped = true;
    is_mixing = false;
    return true;
  }
  return false;
}

bool Mixer::resume() {
  if (is_on && is_mixing_stopped) {
    is_mixing_stopped = false;
    start();
    return true;
  }
  return false;
}

bool Mixer::abort() {
  if (!is_on || !is_mixing) return false;
  is_mixing = false;
  return true;
}

bool Mixer::switch_cover(std::string state) {
  if (!is_on) return false;
  
  if (state.compare("close") == 0 && !is_cover_closed) {
    is_cover_closed = true;
    return true;
  } else if (state.compare("open") == 0 && is_cover_closed) {
    is_cover_closed = false;
    return true;
  }

  return false;
}

int Mixer::set_time(int t = 10) {
  if (!is_on) return -2;

  if (t < time_range[0] || t > time_range[1])
    return -1;
  time = t;
  return time;
}

int Mixer::time_up() {
  if (!is_on) return -2;

  if (time+1 > time_range[1])
    return -1;
  time++;
  return time;
}

int Mixer::time_down() {
  if (!is_on) return -2;

  if (time-1 < time_range[0])
    return -1;
  time--;
  return time;
}

int Mixer::set_temp(int t) {
  if (!is_on) return -2;

  if (t < temp_range[0] || t > temp_range[1])
    return -1;
  temp = t;
  return temp;
}

int Mixer::temp_up() {
  if (!is_on) return -2;

  if (temp+1 > time_range[1])
    return -1;
  temp++;
  return temp;
}

int Mixer::temp_down() {
  if (!is_on) return -2;

  if (temp-1 < time_range[0])
    return -1;
  temp--;
  return temp;
}

int Mixer::set_rpm(int rotation) {
  if (!is_on) return -2;

  if (rotation < rpm_range[0] || rotation > rpm_range[1])
    return -1;
  rpm = rotation;
  return rpm;
}

int Mixer::rpm_up() {
  if (!is_on) return -2;

  if (rpm+1 > rpm_range[1])
    return -1;
  rpm++;
  return rpm;
}

int Mixer::rpm_down() {
  if (!is_on) return -2;

  if (rpm-1 < rpm_range[0])
    return -1;
  rpm--;
  return rpm;
}

bool Mixer::flush() {
  if (!is_on || is_mixing || is_mixing_stopped)
    return false;
  is_flushing = true;
  return true;
}

bool Mixer::flush_end() {
  if (!is_on || !is_flushing)
    return false;
  is_flushing = false;
  return true;
}

bool Mixer::clean() {
  if (!is_on || is_mixing || is_mixing_stopped || is_flushing)
    return -1;
  is_cleaning = true;
  return true;
}

bool Mixer::clean_end() {
  if (!is_on || !is_cleaning)
    return false;
  is_cleaning = false;
  return true;
}

void Mixer::log_state() {
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << "is_on: " << is_on << std::endl;
  std::cout << "is_mixing: " << is_mixing << std::endl;
  std::cout << "is_mixing_stopped: " << is_mixing_stopped << std::endl;
  std::cout << "is_cover_closed: " << is_cover_closed << std::endl;
  std::cout << "time: " << time << std::endl;
  std::cout << "time_range: [" << time_range[0] << "-" << time_range[1] 
    << "]" << std::endl;
  std::cout << "temp: " << temp << std::endl;
  std::cout << "temp_range: [" << temp_range[0] << "-" << temp_range[1] 
    << "]" << std::endl;
  std::cout << "rpm: " << rpm << std::endl;
  std::cout << "rpm_range: [" << rpm_range[0] << "-" << rpm_range[1] 
    << "]" << std::endl;
  std::cout << "is_clean: " << is_cleaning << std::endl;
  std::cout << "is_flush: " << is_flushing << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
}
