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
    std::vector<std::vector<std::string>> labels_num;  //save the label names and label numbers, in shape <label_name,label_num,>
    std::string directory_path;
    std::string name_of_csv_file;
    std::string reg_pattern;
    std::stringstream data_stream;
    std::vector<std::vector<std::string>> row;
    long number_of_lines = 0;
    void getFileList();
    void sortByRanNum(std::vector<std::vector<std::string>>& row);
    static bool CompareTwoRows(std::vector<std::string> i,std::vector<std::string> j);
    void labelToInt(std::vector<std::vector<std::string>>& row);

public:
    CsvMerger(std::string file_name, std::string dir, std::string label_file_path);
    ~CsvMerger();
    void csvReader(std::string csv_file_path);
    void csvWriter(std::string output_file);
    void findCsvFiles();  //find files using regex
    void setRegPattern (std::string pattern);
    std::vector<std::string> getCsvFileList ();
    long getLineNum();
    void addRanNum(long * ran_array, std::string input_file, std::string output_file);
    void cutCsvFile(std::string output_file);


};
