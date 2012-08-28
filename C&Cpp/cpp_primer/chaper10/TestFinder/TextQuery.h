/*
 * File Name: TextQuery.h
 * Auther: linwei
 * E-mail: kinglw8729@gmail.com
 * Project: TestFinder
 * Discripation: TextQuery class
 * Date: 2011-12-13
 */
#ifndef TEXTFINDER_TEXTQUERY_H
#define TEXTFINDER_TEXTQUERY_H
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
class TextQuery{
public:
    // typedef to make declarations easier
    typedef std::vector<std::string>::size_type line_no;
    /* interface:
     *     ReadFile builds internal data structures for the given file
     *     RunQuery finds the given word and returns set of lines on which it
     *     appears
     *     TextLine returns a requested line from the input file
     */
    void ReadFile(std::ifstream &is){
         StoreFile(is);
         BuildMap();
    }
    std::set<line_no> RunQuery(const std::string&) const;
    std::string TextLine(TextQuery::line_no) const;
private:
    // utility functions used by read_file
    void StoreFile(std::ifstream&); // store input file
    void BuildMap(); // associated each word with a set of line numbers
    // remember the whole input file
    std::vector<std::string> linesOfText;
    // map word to set of the lines on which it occurs
    std::map<std::string, std::set<line_no> > wordMap;
};
#endif
