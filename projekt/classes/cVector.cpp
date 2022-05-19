#include "cVector.h"

template <class T> vector<T> cVector<T>::get_vec() { return this->vec; }

template <class T> bool cVector<T>::set_vec(vector<T> vec) {
  if (vec.size() != this->vec.size()) {
    cerr << "Error: Invalid Size of Vector Inside set_vector().\n";
    return false;
  }

  this->vec = vec;
  return true;
}

template <class T> cPoint<T> cVector<T>::get_origin() { return this->origin; }

template <class T> bool cVector<T>::set_origin(cPoint<T> pt) {
  if (pt.get_pts().size() != this->origin.get_pts().size()) {
    cerr << "Error: Invalid Size of cPoint Inside set_origin().\n";
    return false;
  }

  this->origin = pt;
  return true;
}

template <class T> cVector<T> cVector<T>::operator+(const cVector<T> &v) {
  if (this->vec.size() != v.get_vec().size()) {
    cerr << "Error: Attempt to Add Vectors of Incompatible Sizes.\n";
    return *this;
  }
  // TODO.
}

template <class T> cVector<T>::cVector(vector<T> vec) {
  this->vec = vec;

  vector<T> pts(vec.size());
  this->origin = pts;
}

template <class T> cVector<T>::cVector(vector<T> vec, cPoint<T> pt) {
  if (vec.size() != pt.get_pts().size()) {
    cerr << "Error: Invalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  vector<T> temp_pt = pt.get_pts();
  this->origin = temp_pt;
  for (size_t i = 0; i < vec.size(); i++) {
    this->vec.push_back(vec[i] + temp_pt[i]);
  }
}

template <class T> cVector<T>::cVector(cPoint<T> pt1, cPoint<T> pt2) {
  if (pt1.get_pts().size() != pt2.get_pts().size()) {
    cerr << "Error: Incalid Size of Parameters Inside cVector's Constructor.\n";
    return;
  }

  cPoint<T> diff = pt2 - pt1;

  this->vec = diff.get_pts();
  this->origin = pt1;
}

template <class T> cVector<T>::~cVector() {}

// Explicit initialization of available types.
template class cVector<int>;
template class cVector<long>;
template class cVector<long long>;
template class cVector<float>;
template class cVector<double>;
template class cVector<ComplexN<int>>;
template class cVector<ComplexN<long>>;
template class cVector<ComplexN<long long>>;
template class cVector<ComplexN<float>>;
template class cVector<ComplexN<double>>;