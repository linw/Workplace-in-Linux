/*
 * File name: learn_set.cpp 
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-9 
 */
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "stdio.h"
using namespace std;
int main()
{
    vector<int> ivec;
//    set<int> iset;
    for(vector<int>::size_type i = 0; i != 10; ++i){
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.begin(),ivec.end());
    cout<<"ivec size:"<<ivec.size()<<endl;
    cout<<"iset size:"<<iset.size()<<endl;
    set<int>::iterator iter = iset.find(4);
    ++iter;
    cout<<*iter<<endl;
    return 0;
}
