/*
 * File name: test.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-5 
 *
 */
#include <vector>
#include <list>
#include <stack>
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
void ShowCap(){
    vector<int> ivec;
    cout<<"ivec size:"<<ivec.size()<<\
        "   ||   ivec capacity:"<<ivec.capacity()<<endl;
    ivec.push_back(0);
    cout<<"ivec size:"<<ivec.size()<<\
        "   ||   ivec capacity:"<<ivec.capacity()<<endl;
    ivec.clear();
    ivec.reserve(50);
    for(int i = 0; i < 50; ++i)
        ivec.push_back(i);
    cout<<"ivec size:"<<ivec.size()<<\
        "   ||   ivec capacity:"<<ivec.capacity()<<endl;
    ivec.push_back(51);
    cout<<"ivec size:"<<ivec.size()<<\
        "   ||   ivec capacity:"<<ivec.capacity()<<endl;
}
int main()
{
//    vector<int> ivec;
//    cout<<ivec.max_size()<<endl;
//    vector<long> dvec;
//    cout<<dvec.max_size()<<endl;
//    vector<string> svec;
//    cout<<svec.max_size()<<endl;
//    ShowResize();
//    ShowCap();
    string a("abcdefghijklmnopqrstuvwsyz");
    for(string::iterator iter = a.begin();
                         iter != a.end();
                         ++iter)
    {
        cout<<*iter;
    }
    cout<<endl;

    return 0;
}
