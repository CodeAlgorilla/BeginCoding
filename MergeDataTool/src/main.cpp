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
  std::string output_path = argv[3];              //path of output file
  std::string reg_pattern;
  std::vector<std::string> list_of_csv_files;
  if (argc != 4)
  {
    std::cout << "number of arguments false!" << std::endl;
  }

  CsvMerger myMerger(name_of_csv_files, path_of_csv_files);

  reg_pattern = name_of_csv_files + ".csv$";
  myMerger.setRegPattern (reg_pattern);
  myMerger.findCsvFiles ();

  list_of_csv_files = myMerger.getCsvFileList ();
  for (int i = list_of_csv_files.size () -1; i >= 0 ; i--)
  {
    std::cout << list_of_csv_files[i] << std::endl;
    myMerger.csvReader(list_of_csv_files[i]);
    myMerger.csvWriter(output_path);
  }

  std::cout << myMerger.getLineNum () << std::endl;






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

