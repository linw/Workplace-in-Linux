/*
 * File name: 99.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-11-27 
 *
 */
#include <iostream>
#include <list>
using namespace std;
void ReversePrint(list<int> &ilist){
    list<int>::iterator iter = ilist.end();
    --iter;
    for(;iter != ilist.begin();--iter)
        cout<<*iter<<endl;
    cout<<*(ilist.begin())<<endl;
}
int main()
{
    list<int> ilist;
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(3);
    ilist.push_back(4);
    ilist.push_back(5);
    ilist.push_back(6);
    ilist.push_back(7);
    ilist.push_back(8);
    ilist.push_back(9);
    ilist.push_back(10);
    ilist.push_back(11);
    ReversePrint(ilist);
    return 0;
}
