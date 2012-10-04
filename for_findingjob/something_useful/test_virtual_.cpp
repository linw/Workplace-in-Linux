/*
 * =====================================================================================
 *
 *       Filename:    test_virtual_.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-26 10:18:03
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
    cout<<"A"<<endl;
  }
  virtual ~A(){
    cout<<"~A"<<endl;
  }
  void print(){
    cout<<"A"<<endl;
  }
};

class C:virtual
	public A{
public:
  C(){
    cout<<"C"<<endl;
  }
  virtual ~C(){
    cout<<"~C"<<endl;
  }
  void print(){
    cout<<"A"<<endl;
  }
};

class B:virtual
	public A{
public:
  B(){
    cout<<"B"<<endl;
  }
  virtual ~B(){
    cout<<"~B"<<endl;
  }
};

class D:public B, public C{
public:
  D(){
    cout<<"D"<<endl;
  }
  virtual ~D(){
    cout<<"~D"<<endl;
  }
};

// unsigned int how_many_1(int n)
// {
//   unsigned int k = 0;
//   while(n){
//     ++k;
//     n &= (n-1);
//   }
//   return k;
// }

int main()
{
  cout<<sizeof(D)<<endl;
  D* d = new D;
  delete d;
  //  cout<<"hello:::"<<how_many_1(0xffffffff);
  return 0;
}
