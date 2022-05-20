#include "../include/cVector.h"

// -------------------- GET/SET --------------------

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

// -------------------- OPERATORS --------------------

template <class T> cVector<T> cVector<T>::operator+(cVector<T> &v) {
  // Allow only addition of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    cerr << "Error: Attempt to Add Vectors of Incompatible Sizes.\n";
    return *this;
  }

  cVector temp(*this);

  // Add vectors.
  vector<T> v_vec = v.get_vec();
  for (size_t i = 0; i < vec.size(); i++) {
    temp.vec[i] = this->vec[i] + v_vec[i];
  }

  return temp;
}

template <class T> cVector<T> cVector<T>::operator-(cVector<T> &v) {
  // Allow only addition of vectors of the same size.
  if (this->vec.size() != v.get_vec().size()) {
    cerr << "Error: Attempt to Add Vectors of Incompatible Sizes.\n";
    return *this;
  }

  cVector temp(*this);

  // Add vectors.
  vector<T> v_vec = v.get_vec();
  for (size_t i = 0; i < vec.size(); i++) {
    temp.vec[i] = this->vec[i] - v_vec[i];
  }

  return temp;
}

template <class T> cVector<T> cVector<T>::operator=(cVector<T> &v) {
  this->vec = v.vec;
  this->origin = v.origin;
  return *this;
}

template <class T> cVector<T> cVector<T>::operator*(T scalar) {
  for (size_t i = 0; i < this->vec.size(); i++) {
    this->vec[i] = this->vec[i] * scalar;
  }

  return *this;
}

// -------------------- OTHER FUNCTIONALITY --------------------

template <class T> T cVector<T>::norm() {
  T norm = this->vec[0];
  // Start from 1, because of what above.
  for (size_t i = 1; i < this->vec.size(); i++) {
    norm += this->vec[i] * this->vec[i];
  }

  return norm;
}

template <class T> T cVector<T>::abs() { return sqrt((*this).norm()); }

template <class T> T cVector<T>::dot_product(cVector<T> v, T theta) {
  T temp = (*this).norm() * v.norm() * cos(theta);
  return temp;
}

template <class T> cVector<T> cVector<T>::opposite() {
  vector<T> temp;
  for (size_t i = 0; i < this->vec.size(); i++) {
    temp.push_back(this->vec[i]);
  }
  return temp;
}

// -------------------- CONSTRUCTORS --------------------

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
// -------------------- DESTRUCTOR --------------------

template <class T> cVector<T>::~cVector() {}

// -------------------- AVAILABLE TYPES --------------------

// Explicit initialization of available types.
template class cVector<int>;
template class cVector<long>;
template class cVector<long long>;
template class cVector<float>;
template class cVector<double>;

template class cVector<complex<int>>;
template class cVector<complex<long>>;
template class cVector<complex<long long>>;
template class cVector<complex<float>>;
template class cVector<complex<double>>;