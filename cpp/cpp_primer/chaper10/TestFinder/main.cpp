/*
 * File Name: main.cpp
 * Auther: linwei
 * E-mail: kinglw8729@gmail.com
 * Project: TestFinder
 * Discripation: test textQuery class
 * Date: 2011-12-14 
 */
#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "TextQuery.h"
using namespace std;
void PrintResults(const set<TextQuery::line_no>& locs,
                  const string& sought, const TextQuery &file)
{
    typedef set<TextQuery::line_no> lineNums;
    lineNums::size_type size = locs.size();
    cout<<"\n"<<sought<<" occurs "
        <<size<<" ";
    lineNums::const_iterator it = locs.begin();
    for(;it != locs.end(); ++it){
        cout<<"\t(line "
            <<(*it) + 1<<") "
            <<file.TextLine(*it)<<endl;
    }
}
int main()
{
    ifstream infile("data.dat");
    TextQuery tq;
    tq.ReadFile(infile);
    vector<int> a;
    if(a == b) cout<<"sjdfkjsdl"<<endl;
    cout<<"hello world"<<endl;
    cout<<"hellos wordl"<<endl;
    while(true){
        cout<<"enter word to look for, or q to quit:";
        string s;
        cin>>s;
        if(!cin||s=="q") break;
        set<TextQuery::line_no> locs = tq.RunQuery(s);
        PrintResults(locs, s, tq);
    }
    return 0;
}
