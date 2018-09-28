// This is a generator of random number, in order to generate random number in a specific range without duplicate.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class RandomNumberGenerator {

private:
  long begin;
  long end;
  long * randomArray;
  void generateRandomArray();

public:
  RandomNumberGenerator(long begin_of_array_, long end_of_array_);
  void setStart(long start_of_range);
  void setEnd(long end_of_range);
  long getInitialArray();
  long * getRandomArray();
  ~RandomNumberGenerator();

};
