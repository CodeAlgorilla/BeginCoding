// This is the cpp file of the csv merger
#include "merger.h"
#include <fstream>
#include <regex>
#include <strings.h>
#include <sstream>
#include <algorithm>
#include <dirent.h>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <iostream>

CsvMerger::CsvMerger(std::string file_name, std::string dir_path)
{

  name_of_csv_file = file_name;
  directory_path = dir_path;
  number_of_lines = 0;
  data_stream.clear ();
}

CsvMerger::~CsvMerger ()
{

}

void CsvMerger::findCsvFiles ()
{
  getFileList ();
  boost::regex reg(reg_pattern);

  for (int i = 0; i < list_of_files.size (); i++)
  {
    if(boost::regex_search (list_of_files[i],reg))
    {
      list_of_csv_files.push_back (list_of_files[i]);
    }
  }
//  for(int i=0; i < list_of_csv_files.size (); i++)
//  {
//    std::cout << list_of_csv_files[i] << "\t"<< i << std::endl;
//  }
}

void CsvMerger::csvReader (std::string csv_file_path)
{
  std::ifstream csv_file;
  csv_file.open (csv_file_path, std::ios::in);
  if (!csv_file.is_open ())
  {
    std::cout << "fail to open file: " << csv_file_path << std::endl;
  }
  std::string line;
  while(csv_file.good())
  {
    std::getline (csv_file, line,'\n');
    if (line.length () != 0)
    {
      data_stream << line << '\n';
    }
    number_of_lines++;
  }
  std::cout << data_stream.str ();
  csv_file.close ();
}

void CsvMerger::csvWriter (std::string output_file)
{
  std::ofstream merged_file;
  merged_file.open(output_file, std::ios::out);
  if (!merged_file.is_open ())
  {
    std::cout << "fail to open merged_file: " << output_file <<std::endl;
  }
  merged_file << data_stream.str();
  merged_file.close ();
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

//  std::cout << list_of_files.size ()<<std::endl;
//  for(int i=0; i < list_of_files.size (); i++)
//  {
//    std::cout << list_of_files[i] << "\t"<< i << std::endl;
//  }
}

void CsvMerger::setRegPattern (std::string pattern)
{
  reg_pattern = pattern;
}

std::vector<std::string> CsvMerger::getCsvFileList ()
{
  return list_of_csv_files;
}

long CsvMerger::getLineNum ()
{
  return number_of_lines;
}

void CsvMerger::addRanNum ()
{

}
