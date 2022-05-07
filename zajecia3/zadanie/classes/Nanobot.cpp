#include "Nanobot.h"

vector<Nanobot::_info> Nanobot::bots_info;
vector<Nanobot::radiation_data> Nanobot::radiation_list;

Nanobot::Nanobot(double frequency_val, double rotation_val,
                 bool is_radiation_sampling, double radiation_sampling_time)
    : id(bots_info.size() + 1), min_frequency(3.0f), max_frequency(3e6f),
      spawn({0.0f, 0.0f}), min_speed(0.01f), max_speed(50.0f), min_move(0.001f),
      max_move(10000.0f), radiation_min_interval(0.01), min_radiation(1e-6f),
      max_radiation(1e3f) {
  bots_info.push_back();

  double good_frequency; // Determine if provided frequency is valid.
  this->frequency_val = (good_frequency = set_frequency(frequency_val)) > 0
                            ? good_frequency
                            : 3e2; // Default frequency.
  is_frequency_change = false;
  position = spawn;
  is_position_change = false;
  speed = 0.0f;

  this->rotation_val = set_rotation(rotation_val);
  is_rotation_change = this->rotation_val != 0 ? true : false;

  this->radiation_val = set_radiation();
  is_radiation_change = false;
  radiation_avg = 0.0f;
  radiation_total = 0.0f;
  radiation_lifetime = 0.0f;
  radiation_no_sample = 0;
  is_radiation_reset = false;
  this->is_radiation_sampling = is_radiation_sampling;
  radiation_sampling_time = set_radiation_sampling_time(0.1f);
  radiation_list.push_back({id, 0.0f});

  family_sibling_pos = spawn;
  is_family_search = false;
  attatched_walls.fill(false);
}

Nanobot::~Nanobot() {
  // Remove id from id list.
  for (size_t i = 0; i < ids.size(); i++)
    if (id == ids[i]) {
      ids.erase(ids.begin() + i);
      break;
    }

  // Remove entry from radiation list.
  for (size_t i = 0; i < radiation_list.size(); i++)
    if (id == radiation_list[i].bot_id) {
      radiation_list.erase(radiation_list.begin() + i);
      break;
    }
}

// Frequency.
double Nanobot::set_frequency(double frequency_val) {
  if (frequency_val < min_frequency || frequency_val > max_frequency) {
    cerr << "Element 'frequency_val' outside boundaries.";
    return -1.0f;
  }

  return (this->frequency_val = frequency_val);
}

double Nanobot::find_frequency() {
  for (size_t i = 0; i < ids.size(); i++)
    ;
}

double Nanobot::set_rotation(double tetha) {
  rotation_val = tetha - abs(floor(tetha / 360.0)) * 360; // Normalize.
  return rotation_val;
}

Nanobot::gps Nanobot::set_position(double r, double speed, double tetha) {
  if (r < min_move || r > max_move) {
    return {-1.0, -1.0};
  } else if (speed < min_speed || speed > max_speed) {
    return {-1.0, -1.0};
  }
  set_rotation(tetha);
  this->speed = speed;
  return position = {
             position.x + r * (double)cos(this->rotation_val * PI / 180),
             position.y + r * (double)sin(this->rotation_val * PI / 180)};
}

double Nanobot::set_radiation() {
  // Generate radiation value as random number.
  random_device rd;  // Random number from hardware.
  mt19937 gen(rd()); // Seed the generator.
  uniform_real_distribution<double> distr(
      min_radiation,
      max_radiation + 1); // Range. +1, so can generate invalid numbers.
  double radiation_val = distr(gen); // Random number.

  if (radiation_val < min_radiation || radiation_val > max_radiation) {
    cerr << "Invalid radiation.";
    return this->radiation_val;
  }
  return this->radiation_val = radiation_val;
}

double Nanobot::set_radiation_sampling_time(double time) {
  if (time < radiation_min_interval) {
    cerr << "Too short interval in between radiation measuring.\n Using "
            "last valid value instead.";
    return this->radiation_sampling_time;
  }
  return (this->radiation_sampling_time = time);
}

// double Nanobot::update_pos_const(double x, double tetha) {}
// double Nanobot::measure_radiation() {}
// double Nanobot::avg_radiation() {}
// double Nanobot::total_radiation() {}
// Nanobot::gps Nanobot::find_sibling() {}
// int Nanobot::attatch_sibling(int wall) {}
// int Nanobot::detatch_sibling(int wall) {}

void Nanobot::log_state() {
  cout << "--------------------------------------------------\n";
  cout << "\tNanobot's state:" << endl;
  cout << "--------------------------------------------------\n";
  cout << "BotID: " << id << endl;
  cout << "Frequency: " << frequency_val << " [kHz]" << endl;
  cout << "Position: (" << position.x << ", " << position.y
       << ") [m] from point (0, 0)." << endl;
  cout << "Move speed: " << speed << " [m/s]" << endl;
  cout << "Rotation: " << rotation_val << " [deg]" << endl;
  cout << "Last measured radiation value: " << radiation_val << " [Sv]" << endl;
  cout << "Avearage radiation suffered: " << radiation_avg << " [Sv]" << endl;
  cout << "Total radiation suffered since reset: " << radiation_total << " [Sv]"
       << endl;
  cout << "Total radiation suffered in lifetime: " << radiation_lifetime
       << " [Sv]" << endl;
  cout << "Number of radiation samplings: " << radiation_no_sample << endl;
  cout << "Time between samplings: " << radiation_sampling_time << " [s]"
       << endl;
  cout << "Is currently sampling: ";
  is_radiation_sampling ? cout << "true\n" : cout << "false\n";
  cout << "Nearest sibling position: (" << family_sibling_pos.x << ", "
       << family_sibling_pos.y << ") [m]" << endl;
  cout << "Siblings attatched to walls:" << endl;
  for (size_t i = 0; i < attatched_walls.size(); i++) {
    cout << "\tWall " << i << " : ";
    attatched_walls[i] ? cout << "true\n" : cout << "false\n";
  }
  cout << "--------------------------------------------------\n";
}

void Nanobot::log_shared_state() {
  cout << "--------------------------------------------------\n";
  cout << "\tNanobots'  State" << endl;
  cout << "--------------------------------------------------\n";
  cout << "IDs of all bots:" << endl;
  for (size_t i = 0; i < ids.size(); i++)
    cout << "\t" << ids[i];
  cout << endl;
  cout << "Radiation values of each bot: " << endl;
  for (size_t i = 0; i < radiation_list.size(); i++)
    cout << "\tId: " << radiation_list[i].bot_id
         << " | value: " << radiation_list[i].radiation_val << endl;
  cout << "--------------------------------------------------\n";
}
