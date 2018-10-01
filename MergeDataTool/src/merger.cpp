// This is the cpp file of the csv merger
#include "merger.h"
#include <fstream>
#include <regex>
#include <strings.h>
#include <sstream>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include <sys/statfs.h>

CsvMerger::CsvMerger(std::string file_name, std::string file_path)
{
  name_of_csv_file = file_name;
  directory_path = file_path;
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
  DIR *dir;
  DIR *new_dir;
  struct dirent *dirptr;
  if ((dir = opendir (directory_path.c_str ())) == NULL)
  {
    std::cout << "open directory false!" <<std::endl;
    exit(-1);
  }

  while((dirptr = readdir (dir)) != NULL)
  {
    if (strcmp(dirptr->d_name, ".") == 0 || strcmp(dirptr->d_name, "..") == 0)
    {
      continue;
    }
    if (dirptr->d_type == DT_DIR)
    {
      std::string new_path = directory_path + "/" + dirptr->d_name;
      new_dir = opendir(new_path.c_str ());
      continue;
    }
    list_of_files.push_back (dirptr->d_name);
    std::cout << dirptr->d_name <<std::endl;
  }
  closedir (dir);

  std::cout << sizeof list_of_files << std::endl;
  for (int i=0; i < sizeof list_of_files; i++)
  {
    std::cout << list_of_files[i].c_str ()<<  "\t" << i << std::endl;
  }


}
