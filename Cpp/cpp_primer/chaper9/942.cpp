/*
 * File name: 942.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-7 
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
using namespace std;
void GetWords(stack<string> &target){
    string s;
    while(cin>>s){
        target.push(s);
    }
}
int main()
{
    stack<string> target;
    GetWords(target);
    cout<<target.size()<<endl;
    while(!target.empty())
    {
        cout<<target.top().c_str()<<endl;
        target.pop();
    }
    return 0;
}
