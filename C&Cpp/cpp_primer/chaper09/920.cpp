/*
 * File name: 920.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-5 
 *
 */
#include <vector>
#include <list>
#include <iostream>
using namespace std;
bool compare(const vector<int> &source, const list<int> &target){
    vector<int> tmp;
    for(list<int>::const_iterator iter = target.begin();
                                  iter != target.end();
                                  ++iter)
    {
        tmp.push_back(*iter);
    }
//    if(tmp == source) return true;
    return false;
}
int main()
{
    vector<int> source;
    list<int> target;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    source.push_back(4);
    source.push_back(5);
    source.push_back(6);
    source.push_back(7);
    target.push_back(1);
    target.push_back(2);
    target.push_back(3);
    target.push_back(4);
    target.push_back(5);
//    target.push_back(6);
    target.push_back(7);
    if(compare(source, target)) cout<<"same!"<<endl;
    else cout<<"different!"<<endl;
    return 0;
}
