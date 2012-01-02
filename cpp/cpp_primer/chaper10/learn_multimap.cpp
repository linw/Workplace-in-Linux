/*
 * File name: learn_multimap.cpp 
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-9 
 * Descripation: 10.26
 */
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include "stdio.h"
using namespace std;
void FindAndErase(multimap<string, string> &authorBook,
                  const pair<string, string> &searchItem)
{
   ; 
}
bool AlreadyHave(multimap<string, string> &mulMap,
                 const pair<string, string> &searchItem)
{
    multimap<string, string>::iterator begin = mulMap.lower_bound(searchItem.first);
    multimap<string, string>::iterator end = mulMap.upper_bound(searchItem.first);
    while(begin != end){
//        cout<<begin->second<<begin->first;
        if(begin->second == searchItem.second)
            return true;
        ++begin;
    }
    return false;
}
int main(int argc, char **argv){
    multimap<string, string> authorBook;
    string author("");
    string book("");
    while(cin>>author>>book){
//        cout<<author<<book;
        if(AlreadyHave(authorBook, make_pair(author, book)))
            continue;
        authorBook.insert(make_pair(author, book));
    }
    cin.clear();
    cout<<authorBook.size()<<endl;
    return 0;
}

