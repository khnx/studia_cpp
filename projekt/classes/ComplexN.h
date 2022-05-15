#ifndef CLASS_COMPLEX_N
#define CLASS_COMPLEX_N

#include <cmath>
#include <iostream>
using namespace std;

template <class T = int> class ComplexN {
protected:
  constexpr static double pi = 3.14159265359F;

private:
  T re;
  T im;

public:
  ComplexN<T> operator+(const ComplexN<T> &); // Add.
  void operator+=(const ComplexN<T> &);       // Add to self.
  ComplexN<T> operator-(const ComplexN<T> &); // Substract.
  void operator-=(const ComplexN<T> &);       // Substract from self.
  ComplexN<T> operator*(const ComplexN<T> &); // Multiplication.
  void operator*=(const ComplexN<T> &);       // Multiplication of self.
  ComplexN<T> operator/(const ComplexN<T> &); // Division.
  void operator/=(const ComplexN<T> &);       // Division of selt.
  ComplexN<T> operator^(const size_t);        // Natural powerset.

  ComplexN<T> conjugate(); // Complex conjugate number.
  T norm();                // Norm function
  T norm_square();         // Square norm function.
  T arg();                 // Argument function.

  ComplexN(T = 0, T = 0);
  ~ComplexN();

  // Display complex number.
  friend ostream &operator<<(ostream &out, const ComplexN<T> z) {
    if (z.re != 0 && z.im != 0)
      cout << "(" << z.re << ", " << z.im << "i)";
    else if (z.re == 0 && z.im != 0)
      cout << z.im << "i";
    else
      cout << z.re;

    return cout;
  }
};

#endif // -- class ComplexN