#include "include/cPoint.h"
#include "include/cVector.h"

#include <complex>
#include <iostream>

int main() {

  cPoint<double> p1({3, 1, 8});
  cPoint<double> p2({5, 3, 2});
  cPoint<double> p3({3, 0, 9});
  cPoint<double> p4({2, 5, 5});

  cPoint<double> a1({2, 1, 4, 25, 22, 89, 0});
  cPoint<double> a2({1, 3, 5, 42, 54, 12, 8});
  cPoint<double> a3({3, 4, 9, 34, 21, 45, 54});
  cPoint<double> a4({0, 1, 4, 21, 14, 43, 45});

  cVector<double> v1(a1, a2);
  cVector<double> v2(a3, a4);

  complex<double> z1(1, 1);
  complex<double> z2(3, -2);
  complex<double> z3(1.4, 9.8);
  complex<double> z4(4.5, 7.3);
  complex<double> z5(-4.3, 3.7);
  complex<double> z6(-8.9, 3.5);
  complex<double> z7(4.2, 8.9);
  complex<double> z8(-1.2, 7.2);

  cPoint<complex<double>> pz1({z1, z2});
  cPoint<complex<double>> pz2({z3, z4});
  cPoint<complex<double>> pz3({z5, z6});
  cPoint<complex<double>> pz4({z7, z8});

  cVector<complex<double>> vz1(pz1, pz2);
  cVector<complex<double>> vz2(pz3, pz4);

  cout << "vz1: " << vz1 << endl;
  cout << "vz1.norm(): " << vz1.norm() << endl;
  cout << "vz1.abs(): " << vz1.abs() << endl;
  cout << "vz2: " << vz2 << endl;
  cout << "vz2.norm(): " << vz2.norm() << endl;
  cout << "vz2.abs(): " << vz2.abs() << endl;
  cout << "vz1.dot_product(vz2, PI/4): " << vz1.dot_product(vz2, M_PI_4f64)
       << endl;
  cout << "vz1.opposite(): " << vz1.opposite() << endl;
  cout << "z1 * (-1.0): " << z1 * -1.0 << endl;

  return 0;
}