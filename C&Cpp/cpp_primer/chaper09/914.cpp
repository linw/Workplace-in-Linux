/*
 * File name: 914.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-4 
 *
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;
void inputString(vector<string> &stringVector){
    string s;
    while(cin>>s){
        stringVector.push_back(s);
    }
}
void outputString(vector<string> &stringVector){
    for(vector<string>::iterator iter = stringVector.begin();
                                 iter != stringVector.end();
                                 ++iter)
    {
        cout<<(*iter).c_str()<<endl;
    }
}

int main()
{
    vector<string> sv;
    inputString(sv);
    outputString(sv);
    return 0;
}
