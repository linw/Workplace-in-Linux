/*
 * File name: 939.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-6 
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
void fun(const string &sentence){
    string letter("abcdefghijklmnopqrstuvwsyz"\
                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    size_t maxLength = 0;
    size_t minLength = INT_MAX;
    size_t length = 0;
    string maxString;
    string minString;
    string::size_type pos = 0;
    string::size_type pos1 = 0;
    while((pos1 = sentence.find_first_not_of(letter, pos))
               != string::npos){
        length = pos1 - pos;
        cout<<pos1<<pos<<endl;
        if(length > maxLength){
            maxLength = length;
            maxString = sentence.substr(pos, length);
        }
        if(length < minLength && length != 0){
            minLength = length;
            minString = sentence.substr(pos, length);
            cout<<minString.c_str()<<endl;
        }
        pos = pos1 + 1;
    }
   string s = "";
   cout<<"MaxWord is :"<<maxString.c_str()
       <<" and it's length is "<<maxLength<<endl; 
   cout<<"MinWord is :"<<minString.c_str()
       <<" and it's length is "<<minLength<<endl; 
}
int main()
{
    string line1 = "We were her  pride of 10 she named us:";
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and   perspicacious pacific Suzanne";
    string sentence = line1 + " " + line2 + " " + line3;
    fun(sentence);
    return 0;
}

