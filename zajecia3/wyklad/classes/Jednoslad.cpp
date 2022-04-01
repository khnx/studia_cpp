#include <Jednoslad.h>

Jednoslad::Jednoslad() {
  rozmiar_kola = 0.0;
  strncpy(nazwa, "", 1);
}

Jednoslad::Jednoslad(float rk, const char *n) : rozmiar_kola(rk) {
  strncpy(nazwa, n, 30);
}

Jednoslad::~Jednoslad() {

}

void Jednoslad::wypiszDane() {
  std::cout << std::endl << rozmiar_kola << " " << nazwa << std::endl;
}

void Jednoslad::sprawdz() {

}

Rower::Rower() {
  przerzutki_przod = 0;
  przerzutki_tyl = 0;
}

Rower::Rower(float rk, const char *n, int pt, int pp) :
  Jednoslad(rk, n), przerzutki_tyl(pt), przerzutki_przod(pp) {
  
}

void Rower::wypiszDane() {
  std::cout << rozmiar_kola << " " << nazwa << " "
  << przerzutki_przod << " " << przerzutki_tyl << std::endl;
}