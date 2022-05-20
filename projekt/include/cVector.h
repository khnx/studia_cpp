#ifndef CLASS_VECTOR
#define CLASS_VECTOR

#include <cmath>
#include <iostream>
#include <vector>

#include "cPoint.h"

template <class T> class cVector : private cPoint<T> {
protected:
  vector<T> vec;    // Free vector.
  cPoint<T> origin; // Vector starting point.

public:
  vector<T> get_vec();
  bool set_vec(vector<T>);
  cPoint<T> get_origin();
  bool set_origin(cPoint<T>);

  cVector<T> operator+(cVector &);
  cVector<T> operator-(cVector &);
  cVector<T> operator=(cVector &);
  cVector<T> operator*(T);

  T norm();
  T abs();
  cVector<T> opposite();
  cVector<T> translate(cVector<T>);
  T dot_product(cVector<T>, T);
  T cross_product_theta(cVector<T>);
  cVector<T> cross_product(cVector<T>);

  cVector(vector<T> = {0, 0, 0}); // Vector with coordinates.
  cVector(vector<T>, cPoint<T>);  // Vector with coordinates + starting point.
  cVector(cPoint<T>, cPoint<T>);  // Two points.
  ~cVector();

  friend ostream &operator<<(ostream &out, const cVector<T> &v) {

    cout << "(";
    for (size_t i = 0; i < v.vec.size(); i++) {
      cout << v.vec[i];
      if (i < v.vec.size() - 1)
        cout << ", ";
    }
    cout << ")";
    return cout;
  }
};

#endif // -- class cVectors