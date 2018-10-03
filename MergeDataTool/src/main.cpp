/****************************************************************
 *
 * This is the tool of merging csv files and add a random number
 * to each row.
 *
 * Author: Wei Ma
 *
 *
 *
 *
 *
 *
 *
*****************************************************************/
#include <iostream>
#include "random_number_generator.h"
#include "merger.h"
#include <fstream>

int main(int argc, char * argv[])
{
  std::string name_of_csv_files = argv[1];        //name of the csv files which we want to merge
  std::string path_of_csv_files = argv[2];        //path of the csv files
  std::string output_file = argv[3];              //name of output file
  std::string output_path = argv[4];              //path of output file
  std::string reg_pattern;

  CsvMerger myMerger(name_of_csv_files, path_of_csv_files);

  reg_pattern = name_of_csv_files + ".csv$";

  if (argc != 5)
  {
    std::cout << "number of arguments false!" << std::endl;
  }

  std::regex reg(reg_pattern);

  std::cout << reg_pattern << std::endl;

  myMerger.getFileList ();





//  RandomNumberGenerator generator (0,20);
//  long * array;
//  array = generator.getRandomArray ();

//  std::cout << "Hello World!" << std::endl;
//  for (int i = 0; i < 20; i++)
//  {
//    std::cout << array[i] << std::endl;
//  }
//  std::cout << "in the end,ooooo" << std::endl;
  return 0;
}

