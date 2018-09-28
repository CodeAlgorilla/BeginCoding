#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_number_generator.h"
#include <algorithm>
#include <iostream>
#include <time.h>

RandomNumberGenerator::RandomNumberGenerator (long begin_of_array, long end_of_array)
{
  setStart(begin_of_array);
  setEnd(end_of_array);
  randomArray = new long[end - begin];
  for (long i = 0; i < (end - begin); i++)
  {
    randomArray[i] = i;
  }

}

void RandomNumberGenerator::setStart (long start_of_range)
{
  begin = start_of_range;
}

void RandomNumberGenerator::setEnd (long end_of_range)
{
  end = end_of_range;
}

void RandomNumberGenerator::generateRandomArray ()
{
  srand((unsigned)time(NULL));
  for (long j = (end - begin - 1); j > 0; j--)
  {
    std::swap(randomArray[j], randomArray[rand()%j]);
  }
}

long * RandomNumberGenerator::getRandomArray ()
{
  generateRandomArray ();
  return randomArray;
}

RandomNumberGenerator::~RandomNumberGenerator ()
{
  delete[] randomArray;
}
