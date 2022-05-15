#include "classes/ComplexN.h"

int main(int argc, char const *argv[]) {

  ComplexN<double> z(0.22, 2);
  ComplexN<double> z1(1, 2);

  cout << "z: " << z << "\nz1: " << z1 << endl;
  cout << "Conjugate: " << z.conjugate() << endl;
  cout << "Norm: " << z.norm() << endl;
  cout << "Norm Square: " << z.norm_square() << endl;
  cout << "Arg: " << z.arg() << endl;

  return 0;
}