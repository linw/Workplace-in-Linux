/*
 * File name: 926.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-5 
 *
 */
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fun(){
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> ivec(ia, ia+11);
    list<int> ilist(ia, ia+11);
    cout<<"output ivec:"<<endl;
    for(vector<int>::const_iterator iter = ivec.begin();
                                    iter != ivec.end();
                                    ++iter)
        cout<<*iter<<" ";
    cout<<endl;
    cout<<"output ilist:"<<endl;
    for(list<int>::const_iterator iter = ilist.begin();
                                    iter != ilist.end();
                                    ++iter)
        cout<<*iter<<" ";
    cout<<endl;
    vector<int>::iterator v_iter = ivec.begin();
    list<int>::iterator l_iter = ilist.begin();
    while(v_iter != ivec.end()){
        if(*v_iter%2 == 0)
            v_iter = ivec.erase(v_iter);
        else 
            ++v_iter;
    }
    while(l_iter != ilist.end()){
        if(*l_iter%2 != 0)
            l_iter = ilist.erase(l_iter);
        else
            ++l_iter;
    }
    cout<<"After compute"<<endl;
    cout<<"output ivec:"<<endl;
    for(vector<int>::const_iterator iter = ivec.begin();
                                    iter != ivec.end();
                                    ++iter)
        cout<<*iter<<" ";
    cout<<endl;
    cout<<"output ilist:"<<endl;
    for(list<int>::const_iterator iter = ilist.begin();
                                    iter != ilist.end();
                                    ++iter)
        cout<<*iter<<" ";
    cout<<endl;
    
}
int main(){
    fun();
    return 0;
}
