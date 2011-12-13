/*
 * File name: word_transform.cpp 
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-8 
 * A program to transform words.
 * Takes two arguments: The first is name of the word transformation file
 *                      The second is name of the input to transform
 */
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "stdio.h"
using namespace std;
//opens in binding it to the given file
ifstream& open_file(ifstream &in, const string &file)
{
    in.close();    //close in case it was already open
    in.clear();    //clear any existing errors
    //if the open fails, the stream will be in an invalid state
    in.open(file.c_str());    //open the file we were given
    return in;    //condition state is good if open succeeded
}
int main(int argc, char **argv){
    //map to hold the word transformation pairs:
    //key is the word to look for in the input; value is word to use in the
    //output
    map<string, string> trans_map;
    string key, value;
    if(argc != 3)
        throw runtime_error("wrong number of arguments");
    //open transformation file and check that open succeeded
    ifstream map_file;
    if(!open_file(map_file, argv[1]))
        throw runtime_error("no transformation file");
    //read the transformation map and build the map
    while(map_file >> key >> value)
        trans_map.insert(make_pair(key, value));
    //ok, now we're ready to do the transformations
    //open the input file and check that the open succeeded
    ifstream input;
    if(!open_file(input, argv[2]))
        throw runtime_error("no input file");
    string line;    //hold each line from the input
    //read the text to transform it a line at a time
    while(getline(input, line)){
        istringstream stream(line);    //read the line a word at a time
        string word;
        bool firstword = true;    //controls whether a space is printed
        while(stream >> word){
            //ok: the actual mapwork, this part is the heart of the program
            map<string, string>::const_iterator map_it =
                                 trans_map.find(word); 
            //if this word is in the transformation map
            if(map_it != trans_map.end())
                //replace it by the transformation value in the map
                word = map_it->second;
            if(firstword)
                firstword = false;
            else
                cout<<" ";    //print space between words
            cout<<word;
        }
            cout<<endl;
    }
            return 0;
}
