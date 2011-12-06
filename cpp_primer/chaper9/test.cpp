/*
 * File name: test.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-5 
 *
 */
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void ShowResize(){
    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    ivec.push_back(4);
    ivec.push_back(5);
    ivec.resize(9,10);
    for(vector<int>::iterator iter = ivec.begin();
                              iter != ivec.end();
                              ++iter)
        cout<<*iter<<endl;
//    ivec.clear();
    vector<int>::iterator iter1 = find(ivec.begin(), ivec.end(),3);
    cout<<"Find "<<*iter1<<endl;
    ivec.erase(ivec.begin(),ivec.end());
    for(vector<int>::iterator iter = ivec.begin();
                              iter != ivec.end();
                              ++iter)
        cout<<*iter<<endl;

}
int main()
{
//    vector<int> ivec;
//    cout<<ivec.max_size()<<endl;
//    vector<long> dvec;
//    cout<<dvec.max_size()<<endl;
//    vector<string> svec;
//    cout<<svec.max_size()<<endl;
    ShowResize();
    return 0;
}
