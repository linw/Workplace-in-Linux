/*
 * File Name: TextQuery.cpp
 * Auther: linwei
 * E-mail: kinglw8729@gmail.com
 * Project: TestFinder
 * Discripation: TextQuery class
 * Date: 2011-12-13
 */
#include <vector>
#include <map>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "TextQuery.h"
using namespace std;
// read input file: store each line as element in linesOfText
void TextQuery::StoreFile(ifstream &is){
    string textLine;
    while(getline(is, textLine))
        linesOfText.push_back(textLine);
}
// finds whitespace-separated words in the input vector
// and puts the word in wordMap along with the line number
void TextQuery::BuildMap(){
    // process each line form the input vector
    for(TextQuery::line_no lineNum = 0;
                lineNum != linesOfText.size();
                ++lineNum)
    {
        // we'll use line to read the text a word at a time
        istringstream line(linesOfText[lineNum]);
        string word;
        while(line>>word){
            // add this line number to the set
            // subscript will add word to the map if it's not already there
            wordMap[word].insert(lineNum);
        }
    }
}

// get the text line with the giving line number.
string TextQuery::TextLine(TextQuery::line_no ln) const{
    if(ln < linesOfText.size())
        return linesOfText[ln];
    throw out_of_range("line number out of range");
}

// find the word where it appears, the result represent as a set<ln>
set<TextQuery::line_no>
TextQuery::RunQuery(const string &queryWord) const
{
    // Note: must use find and not subscript the map directly
    // to avoid adding words to wordMap
    map<string, set<TextQuery::line_no> >::const_iterator
                                    loc = wordMap.find(queryWord);
    if(loc == wordMap.end())
        return set<TextQuery::line_no>(); // not found, reture empty set
    else
        // fetch and return set of line numbers for this word
        return loc->second;
}
