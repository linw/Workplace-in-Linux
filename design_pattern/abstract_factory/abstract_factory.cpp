/*
 * =====================================================================================
 *
 *       Filename:    abstract_factory.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-06 16:21:53
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 抽象工厂:提供一个创建一系列相关或相互依赖对象的接口,而无需指定他们具体
 *                            的类
 * =====================================================================================
 */
#include <iostream>
using namespace std;

// AbstractProductA
class AbstractProductA
{
};

// AbstractProductB
class AbstractProductB
{
};


// AbstractFactory
class AbstractFactory
{
public:
  AbstractFactory(){}
  AbstractFactory(const AbstractFactory& _af){}
  virtual ~AbstractFactory(){}
public:
  virtual AbstractProductA& createProductA() = 0;
  virtual AbstractProductB& createProductB() = 0;
};
