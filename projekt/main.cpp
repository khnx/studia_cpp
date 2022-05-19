#include "include/ComplexN.h"
#include "include/cPoint.h"
#include "include/cVector.h"

#include <iostream>

int main() {

  ComplexN<double> z1(1, 2);
  ComplexN<double> z2(3, 1.3);
  ComplexN<double> z3(1, 32);
  ComplexN<double> z4(0, 12);
  ComplexN<double> z5(0.22, 2);
  ComplexN<double> z6(2.32, -3);
  ComplexN<double> z7(4.78, 5);
  ComplexN<double> z8(9, 4);

  cPoint<ComplexN<double>> az1({z1, z2});
  cPoint<ComplexN<double>> az2({z3, z4});
  cPoint<ComplexN<double>> az3({z5, z6});
  cPoint<ComplexN<double>> az4({z7, z8});

  cPoint<double> a1({2, 1, 4, 25, 22, 89, 0});
  cPoint<double> a2({1, 3, 5, 42, 54, 12, 8});
  cPoint<double> a3({3, 4, 9, 34, 21, 45, 54});
  cPoint<double> a4({0, 1, 4, 21, 14, 43, 45});

  cVector<double> v1(a1, a2);
  cVector<double> v2(a3, a4);

  cVector<ComplexN<double>> vz1(az1, az2);
  cVector<ComplexN<double>> vz2(az3, az4);

  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;

  cout << "v1 + v2: " << v1 + v2 << endl;

  cout << "vz1: " << vz1 << endl;
  cout << "vz2: " << vz2 << endl;

  cout << "vz1 + vz2: " << vz1 + vz2 << endl;
  cout << "vz1 - vz2: " << vz1 - vz2 << endl;

  cVector<ComplexN<double>> vcp;

  vcp = vz1;

  cout << "vcp: " << vcp << endl;

  return 0;
}