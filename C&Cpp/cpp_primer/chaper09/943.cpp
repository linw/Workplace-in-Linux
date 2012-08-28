/*
 * File name: 943.cpp
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
void GetFormual(const string &source){
    string s;
    stack<char> cStack;
    string::const_iterator iter = source.begin();
    while(iter != source.end()){
        if( *iter != ')'){
            cStack.push(*iter);
        }
        else{
            while(cStack.top() != '(' && !cStack.empty()){
                cStack.pop();
            }
            if(cStack.empty())
                cout<<"parenthtess is not matched"<<endl;
            else{
                cStack.pop();
                cStack.push('@');
            }
        }
        ++iter;
    }
    while(!cStack.empty()){
        cout<<cStack.top();
        cStack.pop();
    }
    cout<<endl;

}
int main()
{
    string source("(skdjflsdj)fl)sjdf");

    GetFormual(source);
    return 0;
}
