/*
 * File name: 1018.cpp 
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-8 
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "stdio.h"
using namespace std;
int main()
{
    map<string, vector<string> > mapName;
    string familyName;
    cout<<"Please putin family name now:"<<endl;
    while(cin>>familyName){
        vector<string> svec;
        mapName.insert(make_pair(familyName, svec));
    }
    map<string, vector<string> >::iterator map_iter = mapName.begin();
    while(map_iter != mapName.end()){
        cout<<"input childname of family:"<<map_iter->first<<endl;
        string childName;
        cin.clear();
        while(cin>>childName)
           map_iter->second.push_back(childName);
        ++map_iter;
    }
    cout<<"Please put in the family name which you want to search:"<<endl;
    cin.clear();
    cin>>familyName;
    map_iter = mapName.find(familyName);
    if(map_iter != mapName.end()){
        vector<string>::iterator vec_iter = map_iter->second.begin();
        cout<<"Child name is :"<<endl;
        while(vec_iter != map_iter->second.end()){
            cout<<vec_iter->c_str()<<" ";
            ++vec_iter;
        }
        cout<<endl;
    }
    return 0;
} 

