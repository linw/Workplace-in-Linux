/*
 * File name: 912.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-11-27 
 *
 */
#include <vector>
#include <iostream>
using namespace std;
bool FindInt(vector<int>::iterator begin,
             vector<int>::iterator end, int value){
    for(vector<int>::iterator iter = begin; iter != end; ++iter){
        if(*iter == value) return true;
    }
    return false;
}
int main()
{
    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    if(FindInt(ivec.begin(),ivec.end(),4))
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

