#ifndef TV_H
#define TV_H

#include <iostream>
using namespace std;

class Tv {
private:
  int channel;
  int no_channel;
  int loudness;
  const int max_loudness;
  bool is_on;

public:
  explicit Tv(int loudness = 1);
  operator int();
  bool turn_on();
  bool turn_off();
  Tv &operator++();
  Tv &operator++(int);
  int quiter();
  int next_channel();
  int prev_channel();
  int change_channel(int ch);
  void state();
  // Log state.
  friend ostream &operator<<(ostream &out, const Tv v);
};

#endif