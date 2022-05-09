#ifndef CLASS_NANOBOT

#define CLASS_NANOBOT
#define PI 3.14159265359

#include <array>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Nanobot {
private:
  // General.
  const int id;

  // Position.
  typedef struct {    // Absolute position.
    double latitude;  // [m].
    double longitude; // [m].
  } gps;
  gps position;       // Position [m].
  const double range; // Range [m].
  double rotation;    // Rotation around vertical axis [deg].

  // Radiation.
  double radiation;                    // Latest radiation value [Sv].
  double radiation_avg;                // Radiation average [Sv].
  double radiation_total;              // Radiation suffered since reset [Sv].
  double radiation_lifespan_total;     // Radiation suffered in lifetime [Sv].
  int radiation_no_samples;            // Number of samples taken since reset.
  double radiation_sample_interval;    // Time between samplings [s].
  const double min_radiation;          // Min detectable radiation level.
  const double max_radiation;          // Max detectable radiation level.
  const double min_radiation_interval; // Min time between samplings.
  const double max_radiation_interval; // Max time between samplings.

  // Shared.
  typedef struct {
    int id;
    double radiation;     // [Sv].
    double radiation_avg; // [Sv].
    gps position;         // [m].
  } _bot_info;
  static vector<_bot_info> bot_info; // Store info about all bots.
  void update_bot_info(const int id, double radiation, double radiation_avg,
                       gps position);

public:
  // Move in relation to current position.
  double set_rotation(double theta = 90.0f); // Set relative rotation.
  gps set_position(double r = 1.0f,
                   double theta = 0.0f); // Set relative position.

  // Radiation.
  double set_radiation();
  void reset_radiation_count();
  double set_radiation_sample_interval(double timespan = 0.1f);

  // Family.
  int find_nearest_relative(); // Find position of the closest nanobot.

  // Log info.
  void log_state_obj();                    // Log information about object.
  static void log_state();                 // Log information about class.
  static void view_relatives_radiations(); // Show radiations off all bots.

  Nanobot();
  ~Nanobot();
};

#endif // CLASS_NANOBOT