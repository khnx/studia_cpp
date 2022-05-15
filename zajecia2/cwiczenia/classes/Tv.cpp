#include "Tv.h"

Tv::Tv(int loudness) : max_loudness(100) { this->loudness = loudness; }

bool Tv::turn_on() {
  if (is_on)
    return false;
  is_on = true;
  return true;
}

bool Tv::turn_off() {
  if (!is_on)
    return false;
  is_on = false;
  return true;
}

Tv &Tv::operator++() {
  if (this->is_on || this->loudness != this->max_loudness)
    return *this;
  this->loudness++;
  return *this;
}

int Tv::quiter() {
  if (!is_on || loudness <= 0)
    return -1;
  return loudness--;
}

Tv &Tv::operator++(int) {
  if (!is_on)
    return *this;
  channel++;
  channel %= no_channel;
  return *this;
}

int Tv::next_channel() {
  if (!is_on)
    return -1;
  channel++;
  channel %= no_channel;
  return channel;
}

int Tv::prev_channel() {
  if (!is_on)
    return -1;
  channel--;
  channel = (channel + no_channel) % no_channel;
  return channel;
}

int Tv::change_channel(int ch) {
  if (!is_on || ch >= no_channel || ch < 0)
    return -1;
  channel = ch;
  return ch;
}

// Log state.
ostream &operator<<(ostream &out, const Tv v) {
  std::cout << "TV is: " << v.is_on << std::endl;
  std::cout << "Channel no: " << v.no_channel << std::endl;
  std::cout << "Loudness: " << v.loudness << std::endl;
  return std::cout;
}
