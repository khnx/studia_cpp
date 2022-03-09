#include <iostream>
#include <cstdlib>
#include <string>

#define ARR_ALA 20
#define ARR_T 64
#define ARR_IN 64

int main() {
  
  // Print an array telling Ala
  char ala_arr[ARR_ALA] = {
    [0] = 'a',
    [1] = 'l',
    [2] = 'a',
    [3] = '\0'
  };

  std::cout << ala_arr << std::endl;

  // Print an array with an integer.
  int arr_t[ARR_T] = {
    [0] = 7
  };

  std::cout << arr_t << std::endl;

  // Read from stdin to to an array and print it out to stdout.
  // char arr_in[ARR_IN];
  // std::cin.getline(arr_in, 6);
  // std::cout << arr_in << std::endl;

  std::string napis;
  std::getline(std::cin, napis);
  std::cout << napis << std::endl;

  return EXIT_SUCCESS;
}