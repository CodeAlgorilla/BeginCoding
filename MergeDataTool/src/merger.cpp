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

bool CsvMerger::CompareTwoRows(std::vector<std::string> i,std::vector<std::string> j)
{

    long a = std::atol(((i)[1]).c_str());
    long b = std::atol(((j)[1]).c_str());

    return(a < b);
}

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
      number_of_lines++;
    }
  }
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

void CsvMerger::addRanNum (long * ran_array, std::string input_file, std::string output_file)
{
  data_stream.clear ();
  std::stringstream new_stream;
  std::ifstream merged_csv_file;
  std::ofstream merged_csv_file_ran;
  std::string line;
  new_stream.clear ();
  merged_csv_file.open (input_file, std::ios::in);
  if (!merged_csv_file.is_open ())
  {
    std::cout << "fail to open merged_file: " << input_file << std::endl;
  }
  int i_row= 0;
  while(!merged_csv_file.eof())
    {
        std::vector<std::string> line_data;
        std::getline (merged_csv_file, line, '\n');
        if (line.length () != 0)
        {
            line_data.push_back(line);
            line_data.push_back(std::to_string(ran_array[i_row]));
            line_data.push_back("\n");
            row.push_back(line_data);
            i_row++;
        }
    }
    merged_csv_file.close ();

    new_stream.clear ();
    sortByRanNum(row);
    for (int i = 0; i <i_row; i++)
    {
        std::vector<std::string> temp;
        temp = row[i];
        temp.erase(temp.begin() + 1);
        for(int j = 0; j < temp.size(); j++)
        {
            new_stream << temp[j];
        }

    }
//    std::cout << new_stream.str () << std::endl;
    merged_csv_file_ran.open (output_file, std::ios::out);
    merged_csv_file_ran << new_stream.str ();
    merged_csv_file_ran.close ();
}

void CsvMerger::sortByRanNum (std::vector<std::vector<std::string>>& row)
{
    std::stable_sort(row.begin(),row.end(),CompareTwoRows);
}
