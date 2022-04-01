#ifndef JEDNOSLAD
#define JEDNOSLAD

#include <iostream>
#include <string.h>

class Jednoslad {
protected:
  float rozmiar_kola;
  char nazwa[30];

public:
  Jednoslad();
  Jednoslad(float rk, const char *n);
  ~Jednoslad();

  virtual void wypiszDane();
  void sprawdz();
};

#endif

#ifndef ROWER
#define ROWER

class Rower : protected Jednoslad {
  int przerzutki_tyl;
  int przerzutki_przod;
public:
  Rower();
  Rower(float rk, const char *n, int pt, int pp);

  void wypiszDane();
  Jednoslad sprawdz();
};

#endif