#include "../include/cPoint.h"

template <typename T> cPoint<T> cPoint<T>::operator+(const cPoint<T> &pt) {
  if (this->pts.size() != pt.pts.size()) {
    cerr << "Error: Invalid Point Dimensions.";
    return *this;
  }

  for (size_t i = 0; i < this->pts.size(); i++) {
    this->pts[i] = this->pts[i] + pt.pts[i];
  }

  return *this;
}

template <typename T> cPoint<T> cPoint<T>::operator-(const cPoint<T> &pt) {
  if (this->pts.size() != pt.pts.size()) {
    cerr << "Error: Invalid Point Dimensions.";
    return *this;
  }

  for (size_t i = 0; i < this->pts.size(); i++) {
    this->pts[i] = this->pts[i] - pt.pts[i];
  }

  return *this;
}

template <typename T> cPoint<T> cPoint<T>::operator=(vector<T> pts) {
  this->pts = pts;
  return *this;
}

template <class T> vector<T> cPoint<T>::get_pts() { return this->pts; }

template <class T> bool cPoint<T>::set_pts(vector<T> pts) {
  // Allow only change of values, not size.
  if (this->pts.size() != pts.size()) {
    cerr << "Error: Invalid Size of Vector Inside 'set_pts()'.\n";
    return false;
  }
  this->pts = pts;
  return true;
}

template <class T> cPoint<T>::cPoint(vector<T> pts) {
  // Assign All Values to Private Properties.
  this->pts = pts;
}

template <class T> cPoint<T>::~cPoint() {}

// Explicit declaration of available types.
template class cPoint<int>;
template class cPoint<long>;
template class cPoint<long long>;
template class cPoint<float>;
template class cPoint<double>;
template class cPoint<ComplexN<int>>;
template class cPoint<ComplexN<long>>;
template class cPoint<ComplexN<long long>>;
template class cPoint<ComplexN<float>>;
template class cPoint<ComplexN<double>>;