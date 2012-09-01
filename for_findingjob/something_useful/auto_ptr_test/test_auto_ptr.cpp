/*
 * =====================================================================================
 *
 *       Filename:    test_auto_ptr.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-30 08:18:08
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 测试智能指针的使用
 * =====================================================================================
 */
#include <iostream>
#include <memory>
#include <tr1/memory>
#include <vector>
using namespace std;
int main(int argv, char* args[])
{
  int p;
  //  p = new int;
  std::tr1::shared_ptr<int> ap(new int);
  std::tr1::shared_ptr<int> ap1(ap);
  *ap = 10;
  cout<<hex<<ap.get()<<endl;
  cout<<hex<<ap1.get()<<endl;
  cout<<dec<<*ap1<<endl;
  std::vector<std::tr1::shared_ptr<int> > vptr;
  vptr.push_back(ap);
  vptr.push_back(ap1);
  vptr.push_back(ap);
  for(int i = 0; i < vptr.size(); ++i){
    cout<<hex<<vptr[i].get()<<endl;
    cout<<dec<<*vptr[i]<<endl;
  }
  cout<<"use count:"<<ap.use_count()<<endl;
  vptr.clear();
  cout<<"use count after clear:"<<ap.use_count()<<endl;
  return 0;
}

