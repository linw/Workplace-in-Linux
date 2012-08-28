/*
 * =====================================================================================
 *
 *       Filename:    test_virtual.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-11 23:04:48
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "stdio.h"
using namespace std;
class A{
public:
    A(){print();}
    // A(){ /*cout<<"A()"<<endl;*/}
    virtual void print(){cout<<"Base A"<<endl;}
    // ~A(){cout<<"~A()"<<endl;}
    virtual void print1(){print();}
    virtual ~A(){print();}
};

class B: public A{
public:
    B(){ /*cout<<"B()"<<endl;*/}
    void print(){ cout<<"Sub class B"<<endl;}
    void print1(){ print();}
    ~B(){cout<<"~B()"<<endl;}
};
class C:public B{
public:
    void print(){ cout<<"Sub class C"<<endl;}
    void print1(){ print();}

};
void fun1(){
    cout<<"fun"<<endl;
}


int main(int argc, char const *argv[])
{
    cout<<sizeof(C)<<endl;
    A* p = new C();
    p->print1();
    delete p;
    return 0;
}
// int main()
// {
//     // A a;
//     // a.print();
//     // B b;
//     // b.print();
//     // A *k = &b;
//     // k->print();
//     cout<<sizeof(void*)<<endl;

//     A* p = new A();
//     A* p1 = new A();

//     int ptr,ptr1;

//     memcpy(&ptr,p,4);
//     memcpy(&ptr1,p1,4);
//     cout<<"ptr: "<<hex<<(void*)ptr<<endl;
//     cout<<"ptr1: "<<hex<<(void*)ptr1<<endl;

//     int ptr2;
//     memcpy((void*)ptr2,(void*)ptr,4);
//     cout<<"ptr2: "<<hex<<(void*)ptr2<<endl;

//     void (*fun)() = (void (*)())((void*)ptr2);
//     cout<<sizeof(fun)<<endl;
//     cout<<"fun dir: "<<hex<<(void*)fun<<endl;
//     assert(false);
//     cout<<"hello"<<endl;



//     // cout<<hex<<ptr<<endl;
//     // cout<<hex<<ptr1<<endl;
//     delete p1;
//     delete p;
//     // B* pp = new B();
//     // delete pp;
//     // B ppp;
//     // int i;
//     // cin>>i;
//     return 0;
// }
