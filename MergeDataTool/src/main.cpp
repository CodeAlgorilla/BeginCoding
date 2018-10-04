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
    myMerger.csvReader(list_of_csv_files[i]);
    myMerger.csvWriter(output_path);
  }
  RandomNumberGenerator generator (0,myMerger.getLineNum());
  long * array;
  array = generator.getRandomArray ();
  myMerger.addRanNum (array, output_path, output_path + " _ran_num");

  return 0;
}

