#include <iostream>
using namespace std;

struct osoba {
  char imie[24];
  char nazwisko[24];
  int wiek;
};


auto main() -> int
{
  osoba t[10] = {};
  osoba student{};
  int z{};

  cin >> student.imie;
  cin >> student.nazwisko;
  cin >> student.wiek;

  cin >> t[0].imie;
  cin >> t[0].nazwisko;
  cin >> t[0].wiek;

  cin >> t[1].imie;
  cin >> t[1].nazwisko;
  cin >> t[1].wiek;

  return 0;
}
