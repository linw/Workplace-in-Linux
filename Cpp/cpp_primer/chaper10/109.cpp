/*
 * File name: 109.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-7 
 *
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<string,int> word_count;
    string s;
    while(cin>>s)
        ++word_count[s];
    for(map<string, int>::iterator iter = word_count.begin();
                                   iter != word_count.end();
                                   ++iter)
    {
        cout<<"Key: "<<iter->first<<"  Value: "<<iter->second<<endl;
    }
    return 0;
}

