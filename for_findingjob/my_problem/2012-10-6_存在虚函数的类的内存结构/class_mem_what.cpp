/*
 * =====================================================================================
 *
 *       Filename:    class_mem_what.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-06 11:57:16
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
#include <stdio.h>
using namespace std;

typedef void(*Fun)(void);


class Base
{
public:
  Base(){}
  ~Base(){}
  virtual void f(){ cout<<"Base::f()"<<endl; }
  virtual void g(){ cout<<"Base::g()"<<endl; }
};

class Derive:public Base
{
public:
  Derive(){}
  ~Derive(){}
  void f(){ cout<<"Derive::f()"<<endl; }
  void g(){ cout<<"Derive::g()"<<endl; }
  virtual void h(){ cout<<"Derive::h()"<<endl; }
};


class Derive1:virtual public Derive
{
private:
  virtual void ff(){ cout<<"Derive1::ff()"<<endl; }
};



int
main(void)
{
  Base b;
  Derive1 d;
  Fun pfun;
  int **vtable;
  cout<<sizeof(Derive1)<<endl;;
  // 下面的代码用于输出vtable中的内容
  vtable = (int**)&d;
  cout<<"Derive vtable:"<<*vtable<<"--->"<<endl;
  int i;
  for(i = 0; (Fun)(*vtable)[i]!=NULL&&i<4; ++i){
    pfun = (Fun)(*vtable)[i];
    cout<<hex<<(void*)(*vtable)[i]<<"       ";
    pfun();
  }
  vtable = (int**)(*vtable)[i];
  for(i = 0; (Fun)(*vtable)[i]!=NULL&&i<4; ++i){
    pfun = (Fun)(*vtable)[i];
    cout<<hex<<(void*)(*vtable)[i]<<"       ";
    //    pfun();
  }
  return 0;
}

