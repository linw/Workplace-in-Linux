/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-04 20:49:55
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */

#include <iostream>
using std::endl;
using std::cout;

class ABC
{
};

void ABC()
{
  cout<<"ABC"<<endl;
}

class Base
{
public:
  void f(int i){
    cout<<"Base::f(int)"<<endl;
  }
  virtual void g(float f){
    cout<<"Base::g(float)"<<endl;
  }
};

class Derived:public Base
{
public:
  void g(float f){
    cout<<"Derived::g(float)"<<endl;
  }
};


int main()
{
  ABC();
  Derived a;
  a.f(1);
  a.g(1);
  return 0;
}

