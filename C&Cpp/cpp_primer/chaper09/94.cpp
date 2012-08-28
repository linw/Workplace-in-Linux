/*
 * File name: 94.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-11-26
 *
 */
#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <ctime>
using namespace std;

void showFun(){
    list< deque<int> > vlist;
    deque<int> v1(10,1);
    deque<int> v2(9,2);
    deque<int> v3(8,3);
    vlist.push_back(v1);
    vlist.push_back(v2);
    vlist.push_back(v3);

}
int main()
{
    showFun();
    return 0;
}
