#include "../include/ComplexN.h"

template <typename T> ComplexN<T> ComplexN<T>::operator+(const ComplexN<T> &z) {
  ComplexN temp;
  temp.im = this->im + z.im;
  temp.re = this->re + z.re;
  return temp;
}

template <typename T> void ComplexN<T>::operator+=(const ComplexN<T> &z) {
  *this = *this + z;
}

template <typename T> ComplexN<T> ComplexN<T>::operator-(const ComplexN<T> &z) {
  ComplexN temp;
  temp.im = this->im - z.im;
  temp.re = this->re - z.re;
  return temp;
}

template <typename T> void ComplexN<T>::operator-=(const ComplexN<T> &z) {
  *this = *this - z;
}

template <typename T> ComplexN<T> ComplexN<T>::operator*(const ComplexN<T> &z) {
  // (a, bi)(c, di) = (ac - bd, (ad + bc)i).
  ComplexN<T> temp;
  temp.re = this->re * z.re - this->im * z.im;
  temp.im = this->re * z.im + this->im * z.re;

  return temp;
}

template <typename T> void ComplexN<T>::operator*=(const ComplexN<T> &z) {
  *this = *this * z;
}

template <typename T> ComplexN<T> ComplexN<T>::operator/(const ComplexN<T> &z) {
  // (a, bi)/(c, di) = (a + bi)(c - di)/(c^2 + d^2).
  // ((ac - bd) / (c^2 + d^2), ((ad + bc) / (c^2 + d^2)) i)
  ComplexN<T> temp = {0, 0};
  ComplexN<T> inv_im = {z.re, z.im * (-1)};
  temp = *this * inv_im;
  temp.re = temp.re / (z.re * z.re + z.im * z.im);
  temp.im = temp.im / (z.re * z.re + z.im * z.im);

  return temp;
}

template <typename T> void ComplexN<T>::operator/=(const ComplexN<T> &z) {
  *this = *this / z;
}

template <typename T> ComplexN<T> ComplexN<T>::operator^(const size_t pow) {
  ComplexN<T> temp = *this;
  for (size_t i = 0; i < pow; i++)
    temp = temp * *this;
  return temp;
}

template <typename T> ComplexN<T> ComplexN<T>::conjugate() {
  ComplexN<T> c = {this->re, this->im * (-1)};
  return c;
}

template <class T> ComplexN<T>::ComplexN(T re, T im) {
  this->re = re;
  this->im = im;
}

template <typename T> T ComplexN<T>::norm_square() {
  ComplexN<T> temp = *this * (*this).conjugate();
  return temp.re;
}

template <typename T> T ComplexN<T>::norm() {
  T temp;
  temp = sqrt(static_cast<double>(this->re * this->re + this->im * this->im));
  return temp;
}

template <typename T> T ComplexN<T>::arg() {
  T temp;
  temp = atan(static_cast<double>(this->im / this->re));
  if (this->re < 0)
    temp += this->pi;
  return temp;
}

template <typename T> ComplexN<T>::~ComplexN() {}

// Explicit declaration of all available types.
template class ComplexN<int>;
template class ComplexN<long>;
template class ComplexN<long long>;
template class ComplexN<float>;
template class ComplexN<double>;