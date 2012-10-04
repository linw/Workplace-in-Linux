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
#include <typeinfo>
#include <stdio.h>
using namespace std;

class A
{
public:
virtual void Fun(int number = 10)
{
std::cout << "A::Fun with number " << number;
}
};
class B: public A
{
public:
virtual void Fun(int number = 20)
{
std::cout << "B::Fun with number " << number;
}
};
int main()
{
B b;
A &a = b;
a.Fun();
}



// class A{
// private:
//   int i;
// public:
//   A(){
//     i = 10;
//   }
//   virtual void fun(){
//     cout<<"Hello"<<endl;
//   }
// };
// class B:public A
// {

// };
// typedef   void   (A::*Fun)(); 

// int main(int argv, char* args[])
// {
//   A a;
//   Fun f;
//   int *p = (int*)&a;
//   cout<<hex<<*p<<endl;
//   cout<<dec<<*(p+1)<<endl;
//   B b;
//   p = (int*)&b;
//   cout<<hex<<*p<<endl;
//   cout<<dec<<*(p+1)<<endl;
//   return 0;
// }
// class A
// {
// public:
//   virtual void fun(){
//     cout<<"A"<<endl;
//   }
// };

// class B
// {
// public:
//   virtual void fun(){
//     cout<<"B"<<endl;
//   }
// };

// class C:virtual public A, virtual public B
// {
// };


// int is_bigend()
// {
//   union{
//     int i;
//     char a[sizeof(int)];
//   }k;
//   k.i = 1;
//   return k.a[0];
// }

// void test_bit_struct()
// {
//   struct {
//     int x:1;
//     int y:2;
//     int z:32;
//   } k;
//   k.x = 0;
//   k.y = 1;
//   k.z = 123;
//   cout<<k.x<<k.y<<k.z<<endl;
// }

// int main(int argv, char* args[])
// {
//   cout<<sizeof(A)<<endl;
//   cout<<sizeof(B)<<endl;
//   C* c =  new C;
//   A* kkk = dynamic_cast<A*>(c);
//   kkk->fun();
//   c->A::fun();
//   //  cout<<(typeid(*c) == typeid(C))<<endl;
//   cout<<typeid(*c).name()<<endl;
//   printf("%f\n",5);
//   printf("%d\n",5.01);
//   if(is_bigend()){
//     printf("is minend\n");
//   }
//   test_bit_struct();
//   int i;
//   double k;
//   k = 100.123;
//   i = 10;
//   //  i = static_cast<int>(k);
//   const int m = 10;
//   //  i = const_cast<int>(m);
//   i = static_cast<int>(k);
//   cout<<i<<endl;
//   return 0;
// }
