/*
 * =====================================================================================
 *
 *       Filename:    heap_fun.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-28 09:59:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;


class A
{
public:
  static const int i = 5;
  int num[i];
};

class B
{
public:
  static const A a;
};

inline int sum(int a, int b)
{
  return a+b;
}

int main()
{
  map<string,int> mm;
  mm["linwei"] = 1;
  mm["chihao"] = 2;
  cout<<mm["linwei"]<<endl;
  mm.insert(map<string,int>::value_type("king",2));
  cout<<mm["king"]<<endl;
  A k;
  cout<<k.i<<endl;
  B b;
  cout<<b.a.i<<endl;
  cout<<sum(10,20)<<endl;
  return 0;
}

