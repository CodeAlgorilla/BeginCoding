// This is the head file of csv merger
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <regex>

class CsvMerger
{
private:
  std::vector<std::string> list_of_files;
  std::vector<std::string> list_of_csv_files;
  std::string directory_path;
  std::string name_of_csv_file;
  std::string reg_pattern;
  long number_of_lines;
  void getFileList();

public:
  CsvMerger(std::string file_name, std::string dir);
  ~CsvMerger();
  void csvReader();
  void csvWriter();
  void findCsvFiles();  //find files using regex
  void setRegPattern (std::string pattern);
};
