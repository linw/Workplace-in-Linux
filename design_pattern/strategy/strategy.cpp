/*
 * =====================================================================================
 *
 *       Filename:    strategy.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-11 23:08:29
 *       Last Edit:   2012-7-12 11:34:02
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
// using namespace std;
using std::cout;
using std::endl;
class Strategy
{
public:
  Strategy() { };
  virtual ~Strategy() { };
public:
  virtual void algorithmInterface() = 0;
};


class Context
{
public:
  Context(Strategy* _strategy):strategy(_strategy) { };
  virtual ~Context() { };
private:
  Strategy* strategy;
public:
  virtual void ContextInterface();
  void setStrategy(Strategy* _strategy) { strategy = _strategy; };
};

void Context::ContextInterface()
{
  strategy->algorithmInterface();
}





class ConcreteStrategyA:public Strategy
{
public:
  ConcreteStrategyA():Strategy() { };
  virtual ~ConcreteStrategyA() { };
public:
  void algorithmInterface();
};

void ConcreteStrategyA::algorithmInterface()
{
  cout<<"ConcreteStrategyA"<<endl;
}


class ConcreteStrategyB:public Strategy
{
public:
  ConcreteStrategyB():Strategy() { };
  virtual ~ConcreteStrategyB() { };
public:
  void algorithmInterface();
};

void ConcreteStrategyB::algorithmInterface()
{
  cout<<"ConcreteStrategyB"<<endl;
}



int main()
{
  Strategy* a = new ConcreteStrategyA();
  Strategy* b = new ConcreteStrategyB();
  Context c(b);
  a->algorithmInterface();
  b->algorithmInterface();
  c.ContextInterface();
  c.setStrategy(a);
  c.ContextInterface();
  delete a;
  delete b;
  return 0;
}