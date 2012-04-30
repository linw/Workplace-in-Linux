/*
 * File name: 918.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-5 
 *
 */
#include <deque>
#include <list>
#include <iostream>
using namespace std;
void CopyContainer(const list<int> &source, 
                   deque<int> &target1,
                   deque<int> &target2)
{
    for(list<int>::const_iterator iter = source.begin();
                                  iter != source.end();
                                  ++iter)
    {
        if((*iter)%2 == 0){
            target1.push_back(*iter);
            continue;
        }
        target2.push_back(*iter);
    }
}
int main()
{
    list<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    source.push_back(4);
    source.push_back(5);
    source.push_back(6);
    source.push_back(7);
    deque<int> target1;
    deque<int> target2;
    CopyContainer(source, target1, target2);
    cout<<"target1"<<endl;
    for(deque<int>::iterator iter = target1.begin();
                             iter != target1.end();
                             ++iter)
    {
       cout<<*iter<<endl;
    }
    cout<<"target2"<<endl;

    for(deque<int>::iterator iter = target2.begin();
                             iter != target2.end();
                             ++iter)
    {
       cout<<*iter<<endl;
    }
    return 0;
}
