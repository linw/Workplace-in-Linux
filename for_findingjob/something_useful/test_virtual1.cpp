/*
 * =====================================================================================
 *
 *       Filename:    test_virtual1.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-05 10:18:22
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
using namespace std;
class A{
public:
  virtual void foo(){
    cout<<"A foo"<<endl;
  }
  void pp(){
    cout<<"A pp"<<endl;
  }
};

class B:public A{
public:
  virtual void foo(){
    cout<<"B foo"<<endl;
  }
  void pp(){
    cout<<"B pp"<<endl;
  }
};
union {
  unsigned int i;
  unsigned char a;
}u;

int main()
{
  B b;
  A *pa = &b;
  pa->foo();
  (*pa).foo();
  pa->pp();
  (*pa).pp();
  u.i=0xf0f1f2f3;
  cout<<hex<<u.i<<endl;
  cout<<hex<<int(u.a)<<endl;
  return 0;
}
