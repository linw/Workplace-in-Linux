/*
 * =====================================================================================
 *
 *       Filename:    test_init_list.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-12 23:01:37
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
using namespace std;
class A{
public:
  A(){
    cout<<"construct A"<<endl;
  }
  A(const A& a){
    cout<<"copy construct A"<<endl;
  }
};

class C{
public:
  C(){
    cout<<"construct C"<<endl;
  }
  C(const C& c){
    cout<<"copy construct C"<<endl;
  }
};


class B{
public:
  B(const A& _a, const C& _c):c(_c),a(_a){
    cout<<"construct B"<<endl;
  }
  B(){
  }
private:
  A a;
  C c;
public:
  static A sa;
};


int main(int argv, char* args[])
{
  A a;
  C c;
  B b;
  
  //  b.sa;
  return 0;
}
