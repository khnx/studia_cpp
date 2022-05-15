#include "class/Szablon.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Int: " << f_add<int>(1, 2) << endl;
  cout << "Double: " << f_add<double>(1.0, 2.0) << endl;
  return 0;
}
