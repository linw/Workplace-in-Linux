/*
 * =====================================================================================
 *
 *       Filename:    prototype.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-02 20:57:13
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 原型模式:就是要实现一个接口，该接口包含一个克隆自身的方法
 *
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;

class Prototype
{
public:
  Prototype(){};
  virtual ~Prototype() {};
public:
  virtual Prototype* clone() = 0;
};

class First:public Prototype
{
public:
  First(int _i) { i = _i;};
  virtual ~First() {};
public:
  Prototype* clone();
  void setI(int _i){ i = _i; };
  int getI() { return i;};
private:
  int i;
};

Prototype* First::clone()
{
  Prototype * c = (Prototype*)new First(i);
  return c;
}

int main()
{
  First *k = (First*)new First(10);
  First *p = (First*)k->clone();
  cout<<k->getI()<<endl;
  cout<<p->getI()<<endl;
  delete k;
  delete p;
}
