// This is the cpp file of the csv merger
#include "merger.h"
#include <fstream>
#include <regex>
#include <strings.h>
#include <sstream>
#include <algorithm>
#include <dirent.h>
#include <boost/filesystem.hpp>
#include <iostream>

CsvMerger::CsvMerger(std::string file_name, std::string dir_path)
{
  name_of_csv_file = file_name;
  directory_path = dir_path;
}

CsvMerger::~CsvMerger ()
{

}

void CsvMerger::findCsvFiles (std::regex reg)
{

}

void CsvMerger::csvReader ()
{

}

void CsvMerger::csvWriter ()
{

}

void CsvMerger::getFileList ()
{
  if (boost::filesystem::exists (directory_path) && boost::filesystem::is_directory (directory_path))
  {
    boost::filesystem::recursive_directory_iterator iter(directory_path);
    boost::filesystem::recursive_directory_iterator end;
    while(iter != end)
    {
      if (boost::filesystem::is_regular_file (iter->path ()))
      {
        list_of_files.push_back (iter->path ().c_str ());
      }
      iter++;
    }
  }
  std::cout << list_of_files.size ()<<std::endl;
  for(int i=0; i < list_of_files.size (); i++)
  {
    std::cout << list_of_files[i] << "\t"<< i << std::endl;
  }
}
