#ifndef CLASS_POINT
#define CLASS_POINT

#include <iostream>
#include <vector>

#include "ComplexN.h"

using namespace std;

template <class T> class cPoint {
protected:
  vector<T> pts;

public:
  cPoint<T> operator+(const cPoint<T> &); // Add two points.
  cPoint<T> operator-(const cPoint<T> &); // Substract two points.
  cPoint<T> operator=(const vector<T>);   // Redefine point.

  vector<T> get_pts();
  bool set_pts(vector<T> pts = {0, 0, 0});

  cPoint(vector<T> pts = {0, 0, 0});
  ~cPoint();

  // Show Coordinates Of The Point.
  friend ostream &operator<<(ostream &out, const cPoint<T> point) {
    cout << "(";
    for (size_t i = 0; i < point.pts.size(); i++) {
      cout << point.pts[i];
      if (i < point.pts.size() - 1)
        cout << ", ";
    }
    cout << ")";
    return cout;
  }
};

#endif // -- Class cPoint.