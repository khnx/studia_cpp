#include "classes/ComplexN.h"
#include "classes/cPoint.h"
#include "classes/cVector.h"

#include <iostream>

int main() {

  ComplexN<double> z(0.22, 2);
  ComplexN<double> z1(1, 2);
  ComplexN<double> z2(3, 1.3);
  ComplexN<double> z3(1, 32);
  ComplexN<double> z4(0, 12);

  cPoint<ComplexN<double>> a({z, z1});
  cPoint<ComplexN<double>> b({z2, z3});
  cPoint<ComplexN<double>> c({z3, z4});

  cPoint<double> x({2, 1, 4});
  cPoint<double> y({1, 3, 5});

  cVector<ComplexN<double>> v(a, b);

  v.set_origin(c);

  cout << v << endl;
  cout << v.get_origin() << endl;

  return 0;
}