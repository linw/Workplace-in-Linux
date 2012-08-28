/*
 * =====================================================================================
 *
 *       Filename:    test_protected.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-11 22:42:04
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
class A
{
public:
    int i;
public:
    A(){ i = 0; };
    virtual ~A(){};
    void print(){
         cout<<i<<endl;
     }

    /* data */
};
class B: public A{
// public:
//     using A::i;
public:
     void print(){
         cout<<i<<endl;
     }
};
class C: protected B{
public:
    void print(){
        cout<<i<<endl;
    }
};
int main()
{
    A a;
    for(int i=0; i<10; ++i){
        cout<<i<<endl;
    }
    a.print();
    cout<<a.i<<endl;
    for(int i=0; i<10; ++i){
        cout<<i<<endl;
    }
    return 0;
}
