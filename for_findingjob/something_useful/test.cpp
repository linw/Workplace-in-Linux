#include <iostream>
using namespace std;
class A
{
public:
  A(){
    cout<<"A---------------------"<<hex<<this<<endl;
  }
  A(const A& a){
    cout<<"copy A from-----------"<<hex<<&a<<endl;
    cout<<"copy A to-------------"<<hex<<this<<endl;
  }
  ~A() {
    cout<<"delete----------------"<<hex<<this<<endl;
  }
  A& operator=(const A& a){
    cout<<"=copy from------------"<<hex<<&a<<endl;
    cout<<"=copy to--------------"<<hex<<this<<endl;
    return *this;
  }
};

A test()
{
  A a;
  // cout<<hex<<&a<<endl;
  return a;
}

int main()
{
  A a;
  cout<<"Test start=================================\n";
  a = test();
  cout<<"Test end===================================\n";
  return 0;
}
// #include <iostream>
// using namespace std;
// class A{
// public:
//   void print(){
//     cout<<"king"<<endl;
//   }
// };

// int main()
// {
//   const A a;
//   a.print();
//   return 0;
// }
