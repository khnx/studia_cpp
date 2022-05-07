#include "Nanobot.h"

vector<Nanobot::_bot_info> Nanobot::bot_info;

Nanobot::Nanobot()
    : id(bot_info.size() + 1), range(1e5), min_radiation(1e-6),
      max_radiation(1e3), min_radiation_interval(0.001f),
      max_radiation_interval(3600.0f) {

  // Position.
  this->position = {0.0f, 0.0f};
  this->rotation = 0.0f;

  // Radiation.
  this->radiation = 0.0f;
  this->radiation_avg = 0.0f;
  this->radiation_total = 0.0f;
  this->radiation_lifespan_total = 0.0f;
  this->radiation_no_samples = 0;
  this->radiation_sample_interval = 0.1;

  // Shared.
  this->bot_info.push_back(
      {this->id, this->radiation, this->radiation_avg, this->position});
}

Nanobot::~Nanobot() {
  // Remove id from the list.
  for (size_t i = 0; i < this->bot_info.size(); i++)
    if (this->id == this->bot_info[i].id) {
      this->bot_info.erase(this->bot_info.begin() + i);
      break;
    }
}

void Nanobot::update_bot_info(const int id, double radiation,
                              double radiation_avg, gps position) {
  for (size_t i = 0; i < this->bot_info.size(); i++)
    if (id == this->bot_info[i].id) {
      this->bot_info[i].radiation = radiation;
      this->bot_info[i].radiation_avg = radiation_avg;
      this->bot_info[i].position = position;
    }
}

double Nanobot::set_rotation(double tetha) {
  int sign = signbit(tetha) == 0 ? 1 : -1;
  return this->rotation =
             sign * (this->rotation + (abs(tetha) - abs(floor(tetha / 360.0)) *
                                                        360)); // Normalize.
}

Nanobot::gps Nanobot::set_position(double r, double tetha) {
  if (abs(r) > this->range) {
    cerr << "Error: Movement Too Far Away.\n";
    return {-1, -1};
  }

  set_rotation(tetha);

  this->position = {
      this->position.latitude + r * (double)cos(this->rotation * PI / 180),
      this->position.longitude + r * (double)sin(this->rotation * PI / 180)};

  // Update shared info.
  update_bot_info(this->id, this->radiation, this->radiation_avg,
                  this->position);

  return position;
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
  this->radiation_avg = radiation_total / radiation_no_samples;

  this->radiation = radiation;

  // Update shared info.
  update_bot_info(this->id, this->radiation, this->radiation_avg,
                  this->position);

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

  dist_bot =
      sqrt(pow(this->position.latitude, 2) + pow(this->position.longitude, 2));

  for (size_t i = 0; i < this->bot_info.size(); i++) {
    if (this->id == this->bot_info[i].id)
      continue;

    dist_each = sqrt(pow(this->bot_info[i].position.latitude, 2) +
                     pow(this->bot_info[i].position.longitude, 2));
    dist = abs(dist_bot - dist_each);

    // Skip itself.
    if (i == 0 || (i == 1 && this->id == this->bot_info[0].id)) {
      closest = dist;
      closest_id = bot_info[i].id;
      position = bot_info[i].position;
    }

    if (dist < closest) {
      closest = dist;
      closest_id = this->bot_info[i].id;
      position = bot_info[i].position;
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

void Nanobot::view_relatives_radiations() {
  cout << "Radiation of all nanobots:\n";
  for (size_t i = 0; i < bot_info.size(); i++) {
    cout << "[id: " << bot_info[i].id
         << "] : [radiation: " << bot_info[i].radiation << "]\n";
  }
}

void Nanobot::log_state_obj() {
  cout << "--------------------------------------------------\n";
  cout << "Object information:\n";
  cout << "--------------------------------------------------\n";

  cout << "Id: " << this->id << endl;
  cout << "Position: (" << this->position.latitude << ", "
       << this->position.longitude << ") [m]" << endl;
  cout << "Rotation: " << rotation << " [deg]" << endl;
  cout << "Radiation: " << this->radiation << " [Sv]" << endl;
  cout << "Total radiation suffered since last reset: " << radiation_total
       << " [Sv]" << endl;
  cout << "Total radiation suffered in it's lifespan: "
       << radiation_lifespan_total << " [Sv]" << endl;
  cout << "Number of radiation samples taken since last reset: "
       << radiation_no_samples << endl;
  cout << "Interval between taking samples: " << radiation_sample_interval
       << " [s]" << endl;
}

void Nanobot::log_state() {
  cout << "--------------------------------------------------\n";
  cout << "Class information:\n";
  cout << "--------------------------------------------------\n";

  for (size_t i = 0; i < bot_info.size(); i++) {
    cout << "Id: " << bot_info[i].id << endl;
    cout << "Radiation: " << bot_info[i].radiation << " [Sv]" << endl;
    cout << "Radiation Average: " << bot_info[i].radiation_avg << " [Sv]"
         << endl;
    cout << "Position: (" << bot_info[i].position.latitude << ", "
         << bot_info[i].position.longitude << ") [m]" << endl;
    cout << "-----" << endl;
  }
}