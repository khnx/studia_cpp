#ifndef CLASS_NANOBOT
#define CLASS_NANOBOT

#define PI 3.14159265359

#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

class Nanobot {
private:
  const int id; // Unique id.

  double frequency_val;       // Active frequency [kHz].
  bool is_frequency_change;   // Should frequency be changed.
  const double min_frequency; //[kHz]
  const double max_frequency; //[kHz]

  typedef struct gps { // Coordinates.
    double x;          // Latitude [m].
    double y;          // Longitude [m].
  } gps;

  // Position.
  const gps spawn;         // Default position [m].
  gps position;            // Position in relation to host (0, 0) [m].
  bool is_position_change; // Should position be updated.
  double speed;            // Movement speed [m/s].
  const double min_speed;  // [m/s].
  const double max_speed;  // [m/s]
  const double min_move;   // [m]
  const double max_move;   // [m]

  // Rotation around vertical axis.
  double rotation_val; // How much to rotate from the normal position [deg].
  double is_rotation_change; // Should rotation be changed.

  // Radiation.
  double radiation_val;                // Last measured radiation [Sv].
  bool is_radiation_change;            // Should radiation be changed.
  double radiation_avg;                // Average radiation value [Sv].
  double radiation_total;              // Total radiation suffered [Sv].
  double radiation_lifetime;           // Radiation suffered in lifetime [Sv].
  int radiation_no_sample;             // Num of samples since reset.
  bool is_radiation_reset;             // Should avg be reset.
  bool is_radiation_sampling;          // Should start sampling.
  double radiation_sampling_time;      // Time between samplings [s].
  const double radiation_min_interval; // Minimal time interval of sampling [s].
  const double min_radiation;          // Min detected radiation [Sv].
  const double max_radiation;          // [Sv].

  // All {id, radiation} pairs.
  struct radiation_data {
    int bot_id;
    double radiation_val; // [Sv].
  };
  static vector<radiation_data> radiation_list;

  // Communication within the Nanobots Family.
  gps family_sibling_pos;          // The nearest nanobot's position.
  bool is_family_search;           // Should search for the nearest sibling.
  array<bool, 12> attatched_walls; // Siblings attached to the walls.
  bool is_attatch;                 // Should attatch to a sibling's wall.

  struct _info {
    const int id;
    gps position;
    double speed;
    double radiation_val;
    double radiation_avg;
    double radiation_total;
    double radiation_lifetime;
    double radiation_no_sample;
    gps family_sibling_pos;
    array<bool, 12> attatched_walls;
  };

  static vector<_info> bots_info; // List of all bots.

public:
  double set_frequency(double = 3e2f);
  double find_frequency();
  double set_rotation(double = 0.0f);
  gps set_position(double = 0.0f, double = 1.0f, double = 0.0);
  gps stop_update_pos();
  double measure_radiation();
  double avg_radiation();
  double total_radiation();
  gps find_sibling();
  int attatch_sibling(int);
  int detatch_sibling(int);

  double set_radiation();
  double set_radiation_sampling_time(double = 0.1);

  void log_state();
  static void log_shared_state();

  Nanobot(double = 3e3f, double = 0.0f, bool = false, double = 0.1f);
  ~Nanobot();
};

#endif