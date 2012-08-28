/*
 * File name: test.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-7 
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
void test1(){
    pair<int, string> p1(1,"one");
    cout<<p1.first<<p1.second<<endl;
    cout<<make_pair("linwei", "king").first<<endl;
}
void test2(){
    map<string, int> word_count;
    word_count["linwei"] = 1;
    word_count["linv"] = 2;
    word_count["linwei"]++;
    word_count["linv"] = 3;
//    cout<<word_count["chi"]<<endl;
    cout<<word_count.size()<<endl;
    cout<<word_count["linwei"]<<endl;
}
int main()
{
    test1();
    test2();
    return 0;
}
