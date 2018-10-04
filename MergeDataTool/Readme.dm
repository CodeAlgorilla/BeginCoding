This is a c++ porject to merge a few csv files.
You should at first build the project and then cd to build directory.
use ‘./MergeDataTool <name of files, which you want to merge> <directory that csv files are included> <output directory + name of output file>’ to generate a merged file with random number.

exp
'./MergeDataTool chlor ~/media/extracted_data/20180728/ ~/tmp/merged_data/merged_chlor.csv'

Now the merger will generate two csv files at same time. One is the merged file(tmp. file) and the other is merged file with random number.

Next step for development of this tool is to realisation how to direct add a column of random number into the merged file. Thus this tool will not generate tmp. file.
