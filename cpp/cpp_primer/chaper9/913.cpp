/*
 * File name: 913.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-2 
 *
 */
#include <vector>
#include <iostream>
using namespace std;
vector<int>::iterator FindInt(vector<int>::iterator begin,
                     vector<int>::iterator end, int value){
    for(vector<int>::iterator iter = begin; iter != end; ++iter){
        if(*iter == value) return iter;
    }
}
int main()
{
    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    vector<int>::iterator iter = FindInt(ivec.begin(),ivec.end(),2);
    cout<<*iter<<endl;
    return 0;
}

