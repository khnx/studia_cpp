#include "Nanobot.h"

vector<Nanobot::_bot_info> Nanobot::bot_info;

Nanobot::Nanobot()
    : id(bot_info.size() + 1), range(1e5), min_frequency(3.0f),
      max_frequency(3e8f), min_radiation(1e-6), max_radiation(1e3),
      min_radiation_interval(0.001f), max_radiation_interval(3600.0f) {

  // Position.
  this->position = {0.0f, 0.0f}; // Spawn.
  this->rotation = 0.0f;

  // Frequency.
  this->frequency = 3e3f;

  // Radiation.
  this->radiation = 0.0f;
  this->radiation_avg = 0.0f;
  this->radiation_total = 0.0f;
  this->radiation_lifespan_total = 0.0f;
  this->radiation_no_samples = 0;
  this->radiation_sample_interval = 0.1;

  // Shared.
  this->bot_info.push_back({&(this->id), &(this->frequency), &(this->radiation),
                            &(this->radiation_avg), &(this->position)});
}

Nanobot::~Nanobot() {
  // Remove id from the list.
  for (size_t i = 0; i < this->bot_info.size(); i++)
    if (this->id == *(this->bot_info[i].id)) {
      this->bot_info.erase(this->bot_info.begin() + i);
      break;
    }
}

double Nanobot::set_rotation(double theta) {
  int sign = signbit(theta) == 0 ? 1 : -1;
  return this->rotation =
             sign * (this->rotation + (abs(theta) - abs(floor(theta / 360.0)) *
                                                        360)); // Normalize.
}

Nanobot::gps Nanobot::set_position(double r, double theta) {
  if (abs(r) > this->range) {
    cerr << "Error: You Want To Move Too Far Away.\n";
    return {-1, -1};
  }

  set_rotation(theta);

  this->position = {
      this->position.latitude + r * (double)cos(this->rotation * PI / 180),
      this->position.longitude + r * (double)sin(this->rotation * PI / 180)};

  return position;
}

double Nanobot::set_frequency(double frequency) {
  if (frequency < this->min_frequency || frequency > this->max_frequency) {
    cerr << "Error: Invalid Frequency. I stay with the last one!\n";
    return -1.0;
  }
  return this->frequency = frequency;
}

double Nanobot::set_radiation() {
  // Generate radiation value as random number.
  random_device rd;  // Random number from hardware.
  mt19937 gen(rd()); // Seed the generator.
  uniform_real_distribution<double> distr(
      min_radiation,
      max_radiation + 1);        // Range. +1, so can generate invalid numbers.
  double radiation = distr(gen); // Random number.

  // Radiation outside bounds.
  if (radiation < min_radiation || radiation > max_radiation) {
    cerr << "Radiation outside bounds.";
    if (radiation > max_radiation)
      cerr << "Very high radiation.";
    return -1.0;
  }

  this->radiation_total += radiation;
  this->radiation_lifespan_total += radiation;
  this->radiation_no_samples++;
  this->radiation_avg = this->radiation_total / this->radiation_no_samples;

  this->radiation = radiation;

  return this->radiation;
}

void Nanobot::reset_radiation_count() {
  this->radiation = 0.0f;
  this->radiation_total = 0.0f;
  this->radiation_no_samples = 0;
}

double Nanobot::set_radiation_sample_interval(double timespan) {
  if (timespan < this->min_radiation_interval ||
      timespan > this->max_radiation_interval) {
    cerr << "Invalid radiation sampling time interval.\n";
    return -1;
  }

  return this->radiation_sample_interval = timespan;
}

int Nanobot::find_nearest_relative() {
  double closest;      // Distance from the closest bot.
  int closest_id = -1; // Id of the closest bot.
  double dist_bot;     // Distance from (0, 0) for the bot.
  double dist_each;    // Distance from (0, 0) for each bot.
  double dist;         // Distance between each bot and the bot.
  gps position;

  if (bot_info.size() == 1) {
    cerr << "You're the only one!\n";
    return -1;
  }

  dist_bot =
      sqrt(pow(this->position.latitude, 2) + pow(this->position.longitude, 2));

  for (size_t i = 0; i < this->bot_info.size(); i++) {
    if (this->id == *(this->bot_info[i].id))
      continue;

    dist_each = sqrt(pow(this->bot_info[i].position->latitude, 2) +
                     pow(this->bot_info[i].position->longitude, 2));
    dist = abs(dist_bot - dist_each);

    // Skip itself.
    if (i == 0 || (i == 1 && this->id == *(this->bot_info[0].id))) {
      closest = dist;
      closest_id = *(this->bot_info[i].id);
      position = *(this->bot_info[i].position);
    }

    if (dist < closest) {
      closest = dist;
      closest_id = *(this->bot_info[i].id);
      position = *(this->bot_info[i].position);
    }
  }

  if (closest_id == -1)
    cout << "No relative bots nearby.\n";
  else {
    cout << "Closest relative bot\n\tid: " << closest_id << "\n\tposition: ("
         << position.latitude << ", " << position.longitude << ") [m]" << endl;
  }

  return closest_id;
}

void Nanobot::log_state_obj() {
  cout << "\n--------------------------------------------------\n";
  cout << "Object information:\n";
  cout << "--------------------------------------------------\n";

  cout << this->id << " - Id\n";
  cout << "(" << this->position.latitude << ", " << this->position.longitude
       << ") [m] - Position\n";
  cout << this->rotation << " [deg] - Rotation\n";
  cout << this->frequency << " [Hz] - Frequency\n";
  cout << this->radiation << " [Sv] - Radiation\n";
  cout << this->radiation_total
       << " [Sv] - Total radiation suffered since last reset\n";
  cout << this->radiation_lifespan_total
       << " [Sv] - Total radiation suffered in it's lifespan\n";
  cout << this->radiation_no_samples
       << " - Number of radiation samples taken since last reset\n";
  cout << this->radiation_sample_interval
       << " [s] - Interval between taking samples\n";
  cout << "--------------------------------------------------\n\n";
}

void Nanobot::log_state() {
  cout << "\n--------------------------------------------------\n";
  cout << "Class information:\n";
  cout << "--------------------------------------------------\n";

  for (size_t i = 0; i < bot_info.size(); i++) {
    cout << "Id: " << *(bot_info[i].id) << endl;
    cout << "Frequency: " << *(bot_info[i].frequency) << " [Hz]" << endl;
    cout << "Radiation: " << *(bot_info[i].radiation) << " [Sv]" << endl;
    cout << "Radiation Average: " << *(bot_info[i].radiation_avg) << " [Sv]"
         << endl;
    cout << "Position: (" << bot_info[i].position->latitude << ", "
         << bot_info[i].position->longitude << ") [m]" << endl;
    if (i != bot_info.size() - 1)
      cout << "-----" << endl;
  }
  cout << "--------------------------------------------------\n\n";
}

void Nanobot::view_relatives_radiations() {
  cout << "Radiation of all nanobots:\n";
  for (size_t i = 0; i < bot_info.size(); i++) {
    cout << "[id: " << bot_info[i].id
         << "] : [radiation: " << bot_info[i].radiation << "]\n";
  }
}