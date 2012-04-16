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
    int i;
private:
    int ii;
};
class B:public A{
public:
    B():A(10){cout<<"B()"<<endl;}
private:
    // int i;
    // int ii;
};
int main()
{
    A* p = new B();
    cout<<p->i<<endl;
    cout<<sizeof(B)<<endl;
    return 0;
}
