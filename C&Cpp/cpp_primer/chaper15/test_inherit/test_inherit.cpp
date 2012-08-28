/*
 * =====================================================================================
 *
 *       Filename:    test_inherit.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 11:28:54
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
class A{
public:
    A(int _i){cout<<"A()"<<endl; i = _i;}
    virtual void print()= 0;
    // A(){ i = 1; };
    // int i;
protected:
    int i;
};
class B:public A{
public:
    B(int val):A(i+val){cout<<"B()"<<endl;}
    virtual void print(){ cout<<"B_print()"<<endl;}
private:
    // int i;
    // int ii;
};
int main()
{
    A* p = new B(5);
    // p->print(10);
    p->print();
    // cout<<p->i<<endl;
    cout<<sizeof(B)<<endl;
    return 0;
}
