/*
 * =====================================================================================
 *
 *       Filename:    002_设计包含min函数的栈.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 11:28:54
 *       Compiler:    gcc
 *       Description: 
 *                  题目：定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。要求函数min、push以及
 *                        pop的时间复杂度都是O(1)。
 *                  这道题的主要难点在于pop()的时候如果栈顶就是最小元素，则pop后就很难确定该栈中的最小元素
 *              所以这里加入一个辅助的栈来保存栈中最小的元素
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* next;
}Node, *list;
class MyStack
{
private:
    list oStack;
    list mStack;
public:
    MyStack(){oStack = mStack = NULL;};
    virtual ~MyStack();
    int min();
    void push(int e);
    int pop();
    int top();
    void print_oStack();
    void print_mStack();
};

MyStack:: ~MyStack(){
    while(oStack){
        pop();
    }
}

void MyStack::push(int e){
    list tmp1 = new Node();
    list tmp2 = new Node();
    tmp1->data = e;
    tmp2->data = e;
    tmp1->next = tmp2->next = NULL;
    if(oStack == NULL){
        oStack = tmp1;
        mStack = tmp2;
    }
    else{
        tmp1->next = oStack;
        oStack = tmp1;
        if(mStack->data >= e){
            tmp2->next = mStack;
            mStack = tmp2;
        }
        else delete tmp2;
    }
    // cout<<hex<<mStack<<endl;

}

int MyStack::min(){
    // cout<<hex<<mStack<<endl;
    assert(mStack);
    return mStack->data;
}

int MyStack::pop(){
    assert(oStack);
    int e = oStack->data;
    if(oStack->data == mStack->data){
        list po = oStack;
        list pm = mStack;
        oStack = oStack->next;
        mStack = mStack->next;
        delete po;
        delete pm;
    }
    else {
        list po1 = oStack;
        oStack = oStack->next;
        delete po1;
    }
    return e;
}


int MyStack::top(){
    assert(oStack);
    return oStack->data;
}

void MyStack::print_oStack(){
    assert(oStack);
    list p = oStack;
    while(p){
        cout<<p->data<<"==>";
        p = p->next;
    }
    cout<<endl;
}

void MyStack::print_mStack(){
    assert(mStack);
    list p = mStack;
    while(p){
        cout<<p->data<<"==>";
        p = p->next;
    }
    cout<<endl;    
}



int main(int argc, char const *argv[])
{
    MyStack ms;
    ms.push(10);
    ms.push(2);
    ms.push(8);
    ms.push(5);
    ms.push(1);
    cout << ms.min() << " "<< ms.pop() << endl;
    cout << ms.min() << " "<< ms.pop() << endl;
    cout << ms.min() << " "<< ms.pop() << endl;
    return 0;
}


