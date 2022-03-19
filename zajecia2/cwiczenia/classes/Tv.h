#ifndef TV_H
#define TV_H

class Tv {
private:
  int channel;
  int no_channel;
  int loudness;
  int max_loudness;
  bool is_on;

public:
  bool turn_on();
  bool turn_off();
  int lauder();
  int quiter();
  int next_channel();
  int prev_channel();
  int change_channel(int ch);
  void state();
};

#endif