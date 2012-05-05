/*
 * File name: 927.cpp
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
int FindAndErase(list<string> &source, const string &s){
    int count = 0;
    list<string>::iterator iter = source.begin();
    while(iter != source.end()){
        if(*iter == s){
            iter = source.erase(iter);
            count++;
        }
        else
            ++iter;
    }
    return count;
}
int FindAndErase_deque(deque<string> &source, const string &s){
    int count = 0;
    deque<string>::iterator iter = source.begin();
    while(iter != source.end()){
        if(*iter == s){
            iter = source.erase(iter);
            ++count;
        }
        else ++iter;
    }
    return count;
}
int main()
{
    string a[10] = {"linv", "king", "monkey", "linw", "haohao", "apple", 
                    "king", "linwei", "chihao", "light"};
    list<string> source(a, a + 10);
    FindAndErase(source, "king");
    cout<<"size: "<<source.size()<<endl;
    return 0;
}
