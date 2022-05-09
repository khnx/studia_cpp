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
  gps position;       // [m].
  const double range; // [m].
  double rotation;    // Rotation around vertical axis [deg].

  // Frequency.
  double frequency;           // What frequency to use to communicate with [Hz].
  const double min_frequency; // Min frequency that's available [Hz].
  const double max_frequency; // Max frequency that's available [Hz].

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
  // Pointers, so there's no need to keep track of updating values.
  typedef struct {
    const int *id;
    double *frequency;     // [Hz].
    double *radiation;     // [Sv].
    double *radiation_avg; // [Sv].
    gps *position;         // [m].
  } _bot_info;
  static vector<_bot_info> bot_info; // Store info about all bots.

public:
  // Move in relation to current position.
  double set_rotation(double theta = 90.0f); // Set relative rotation.
  gps set_position(double r = 1.0f,
                   double theta = 0.0f); // Set relative position.

  // Frequency.
  double set_frequency(double frequency); // [Hz].

  // Radiation.
  double set_radiation();       // Check radiation.
  void reset_radiation_count(); // Reset radiation measurments.
  double set_radiation_sample_interval(
      double timespan = 0.1f); // Set time between two radiation samplings.

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