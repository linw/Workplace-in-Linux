/*
 * =====================================================================================
 *
 *       Filename:    mutable_test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月29日 21时39分11秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;
class A{
public:
  A()
  {
    count = 0;
  }
  void ACount() const{
    count++;
  };
  void print(ostream& o){
    o<<"========== Count ================"<<endl;
    o<<count<<endl;
  }
private:
  mutable size_t count;
};

int main()
{
  A a;
  a.ACount();
  a.ACount();
  a.ACount();
  a.ACount();
  a.ACount();
  a.print(cout);
}
