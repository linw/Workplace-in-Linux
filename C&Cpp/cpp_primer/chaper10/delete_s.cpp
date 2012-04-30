/*
 * File name: delete_s.cpp 
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-9 
 * Descripation: 10.24
 * Take three arguments:
 *                       First is ignore file path
 *                       Second is source file path
 *                       Third is target file path
 */
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "stdio.h"
using namespace std;
void delete_s(ifstream &ignore_file,
              ifstream &source_file,
              ofstream &target_file)
{
    set<string> excluded; // set to hold words we'll ignore
    string ignoreWord;
    while(ignore_file>>ignoreWord)
        excluded.insert(ignoreWord);
    string word;
    while(source_file>>word){
        if(excluded.count(word)){
            target_file<<word<<" "<<flush;
            continue;
        }
        if(word[word.size()-1] == 's'){
            word = string(word.begin(), word.end()-1);
        }
        target_file<<word<<" "<<flush;
    }
}

int main(int argc, char **argv)
{
    if(argc != 4)
        throw runtime_error("wrong number of arguments");
    ifstream ignore_file(argv[1]);
    ifstream source_file(argv[2]);
    ofstream target_file(argv[3]);

    delete_s(ignore_file, source_file,target_file);
    return 0;
}

