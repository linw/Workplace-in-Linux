/*
 * =====================================================================================
 *
 *       Filename:    template_method.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-03 17:05:09
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 模板模式:就是基类定义好算法框架,子类只是实现具体每个算法,而不修改算法流程
 * =====================================================================================
 */
#include <iostream>
using std::endl;
using std::cout;


// 基类
class AbstractClass
{
public:
  AbstractClass(){};
  AbstractClass(const AbstractClass& _ac){};
  virtual ~AbstractClass() {};
public:
  void TemplateMethod();
  virtual void operator1() = 0;
  virtual void operator2() = 0;
};

void AbstractClass::TemplateMethod()
{
  operator1();
  operator2();
}


class ConcreteClass:public AbstractClass
{
public:
  ConcreteClass() {};
  ConcreteClass(const ConcreteClass& _cc) {};
  virtual ~ConcreteClass() {};
public:
  void operator1();
  void operator2();
};

void ConcreteClass::operator1()
{
  cout<<"operator 1"<<endl;
}

void ConcreteClass::operator2()
{
  cout<<"operator 2"<<endl;
}

int main()
{
  AbstractClass *p = new ConcreteClass();
  p->TemplateMethod();
  delete p;
  return 0;
}


