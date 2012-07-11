/*
 * =====================================================================================
 *
 *       Filename:    MyStack.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 18:09:23
 *       Compiler:    gcc
 *       Description: MyStack using template
 *
 * =====================================================================================
 */
#ifndef _CHAPER16_MYSTACK_H
#define _CHAPER16_MYSTACK_H

#include <iostream>
using namespace std;
template <typename T>
typedef struct Node
{
    T data;
    Node* next;
};
template <class Type> 
class Stack{
    // struct Node
    // {
    //     Type data;
    //     Node* next;
    // };
public:
    Stack():stack(NULL) { };
    virtual ~Stack(){
        while(stack){
            Node<Type>* tmp = stack;
            stack = stack->next;
            delete tmp;
            tmp = NULL;
        }
    };
    void push(const Type& e);
    Type pop();
    Type top();
    bool empty(){ return stack==NULL? 1:0;};
private:
    Node<Type>* stack;
};
template <class Type> 
void Stack<Type>::push(const Type& e){
    Node<Type>* tmp = NULL;
    tmp = new Node<Type>;
    tmp->data = e;
    tmp->next = stack;
    stack = tmp;
}
template <class Type> 
Type Stack<Type>::pop(){
    Type e = stack->data;
    Node<Type>* tmp = NULL;
    tmp = stack;
    stack = stack->next;
    delete tmp;
    tmp = NULL;
    return e;
};
template <class Type> 
Type Stack<Type>::top(){
    return stack->data;
};
#endif
