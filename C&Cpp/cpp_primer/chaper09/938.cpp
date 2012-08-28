/*
 * File name: 938.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-6 
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string* FindInString1(const string &source){
    string *s = new string[2];
    string number("0123456789");
    string letter("abcdefghijklmnopqrstuvwxyz");
    int pos = 0;
    while((pos = source.find_first_of(number ,pos))
                 != string::npos){
        s[0]+=source[pos];
        ++pos;
    }
    pos = 0; 
    while((pos = source.find_first_of(letter, pos))
                 != string::npos){
        s[1]+=source[pos];
        ++pos;
    }
    return s;
}
string* FindInString2(const string &source){
    string *s = new string[2];
    string number("0123456789");
    string letter("abcdefghijklmnopqrstuvwxyz");
    int pos = 0;
    while((pos = source.find_first_not_of(letter ,pos))
                 != string::npos){
        s[0]+=source[pos];
        ++pos;
    }
    pos = 0; 
    while((pos = source.find_first_not_of(number, pos))
                 != string::npos){
        s[1]+=source[pos];
        ++pos;
    }
    return s;
}
int main()
{
    string source("ab2c3d7r46");
    string *s;
    s = FindInString1(source);
    cout<<s[0].c_str()<<endl;
    cout<<s[1].c_str()<<endl;
    delete []s;
    s = FindInString2(source);
    cout<<s[0].c_str()<<endl;
    cout<<s[1].c_str()<<endl;
    delete []s;

    return 0;
}
