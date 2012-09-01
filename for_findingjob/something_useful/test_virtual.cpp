/*
 * =====================================================================================
 *
 *       Filename:    test_virtual.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-01 12:33:19
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
using namespace std;

class A{
private:
  int i;
public:
  A(){
    i = 10;
  }
  virtual void fun(){
    cout<<"Hello"<<endl;
  }
};
class B:public A
{
  
};
typedef   void   (A::*Fun)(); 

int main(int argv, char* args[])
{
  A a;
  Fun f;
  int *p = (int*)&a;
  cout<<hex<<*p<<endl;
  cout<<dec<<*(p+1)<<endl;
  B b;
  p = (int*)&b;
  cout<<hex<<*p<<endl;
  cout<<dec<<*(p+1)<<endl;
  return 0;
}
