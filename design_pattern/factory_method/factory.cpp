/*
 * =====================================================================================
 *
 *       Filename:    factory.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-31 21:51:53
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 工厂模式，最大的优点使得一个类的实例化延迟到了其子类
 *
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;


class Product
{
public:
  Product(){};
  virtual ~Product() {};
public:
  virtual void print() = 0;
};

class Factory
{
public:
  Factory(){};
  virtual ~Factory(){};
public:
  virtual Product * FactoryMethod() = 0;
};

class ProductA:public Product
{
public:
  ProductA(){};
  ~ProductA(){};
public:
  void print(){
    cout<<"ProductA"<<endl;
  }
};

class FactoryA:public Factory
{
public:
  FactoryA(){};
  ~FactoryA(){};
public:
  Product* FactoryMethod(){
    return (Product*)(new ProductA());
  };
};

int main()
{
  Product *p = NULL;
  FactoryA factoryA;
  p = factoryA.FactoryMethod();
  p->print();
  return 0;
}
