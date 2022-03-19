#include "Tv.h"

bool Tv::turn_on() {
  if (is_on) return false;
  is_on = true;
  return true;
}

bool Tv::turn_off() {
  if ( !is_on) return false;
  is_on = false;
  return true;
}

int Tv::lauder() {
  if ( !is_on || loudness < max_loudness)
    return -1;
  return loudness++;
}

int Tv::quiter() {
  if ( !is_on || loudness <= 0)
    return -1;
  return loudness--;
}

int Tv::next_channel() {
  if ( !is_on)
    return -1;
  channel++;
  channel %= no_channel;
  return channel;
}

int Tv::prev_channel() {
  if ( !is_on)
    return -1;
  channel--;
  channel = (channel + no_channel) % no_channel;
  return channel;
}

int Tv::change_channel(int ch) {
  if ( !is_on || ch >= no_channel || ch < 0)
    return -1;
  channel = ch;
  return ch;
}

#include <iostream>
void Tv::state() {
  std::cout << "TV is: " << is_on << std::endl;
  std::cout << "Channel no: " << no_channel << std::endl;
  std::cout << "";
}
