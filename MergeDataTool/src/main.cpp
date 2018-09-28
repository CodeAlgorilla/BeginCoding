#include <iostream>
#include "random_number_generator.h"

int main()
{
  RandomNumberGenerator generator (0,20);
  long * array;
  array = generator.getRandomArray ();

  std::cout << "Hello World!" << std::endl;
  for (int i = 0; i < 20; i++)
  {
    std::cout << array[i] << std::endl;
  }
  std::cout << "in the end,ooooo" << std::endl;
  return 0;
}

