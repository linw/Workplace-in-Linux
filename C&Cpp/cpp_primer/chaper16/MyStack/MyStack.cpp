/*
 * =====================================================================================
 *
 *       Filename:    MyStack.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 18:09:23
 *       Compiler:    gcc
 *       Description: MyStack using template
 *
 * =====================================================================================
 */
#include <iostream>
#include "MyStack.hpp"
using namespace std;
// virtual Stack::~Stack(){
//     while(stack){
//         list tmp = stack;
//         stack = stack->next;
//         delete tmp;
//         tmp = NULL;
//     }
// }

// void Stack::push(const T& e){
//     list tmp = NULL;
//     tmp = new Node;
//     tmp->data = e;
//     tmp->next = stack;
//     stack = tmp;
// }

// T Stack::pop(){
//     T e = stack->data;
//     list tmp = NULL;
//     tmp = stack;
//     stack = stack->next;
//     delete tmp;
//     tmp = NULL;
//     return e;
// };

// T Stack::top(){
//     return stack->data;
// }

int main(int argc, char const *argv[])
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    while(!s.empty()){
        cout<<s.pop()<<endl;
    }

    return 0;
}
