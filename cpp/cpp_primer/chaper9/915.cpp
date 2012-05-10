/*
 * File name: 915.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-4 
 *
 */
#include <vector>
#include <list>
#include <iostream>
#include <string>
using namespace std;
void inputString(list<string> &stringList){
    string s;
    while(cin>>s){
        stringList.push_back(s);
    }
}
void outputString(list<string> &stringList){
    for(list<string>::const_reverse_iterator iter = stringList.rbegin();
                                 iter != stringList.rend();
                                 ++iter)
    {
        cout<<(*iter).c_str()<<endl;
    }
}

int main()
{
    list<string> sv;
    inputString(sv);
    outputString(sv);
    return 0;
}
