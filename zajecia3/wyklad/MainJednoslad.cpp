#include <Jednoslad.h>

int main(int argc, char const *argv[]) {

  // Przyklad 1 - uzycie statycznej tablicy wskaznikow
  Jednoslad *t[2]{
    [0] = new Jednoslad(29, "Magnum"),
    [1] = new Jednoslad(29, "Magnum 120")
  };

  for (int i = 0; i < 2; i++)
    t[i] -> wypiszDane();
  
  Rower magnum(29, "Magnum", 10, 2);
  magnum.wypiszDane();

  delete t;

  // ----------------------
  // Uzycie dynamicznej tablicy wskaznikow
  int ilosc_elementow = 2;
  Jednoslad **T = nullptr;
  T = new Jednoslad * [ilosc_elementow];
  for (int i = 0; i < ilosc_elementow; i++)
    T[i] = new Jednoslad;
  
  T[0] = new Jednoslad(29, "Magnum");
  T[1] = new Jednoslad(29, "Magnum 120");

  for (int i = 0; i < ilosc_elementow; i++) {
    T[i] -> wypiszDane();
  }

  for (int i = 0; i < ilosc_elementow; i++)
    delete T[i];
  delete T;

  return 0;
}
