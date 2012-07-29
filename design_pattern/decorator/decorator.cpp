/*
 * =====================================================================================
 *
 *       Filename:    decorator.cpp
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
using std::cout;
using std::endl;

class Component
{
public:
  Component() { };
  virtual ~Component() { };
public:
  virtual void operation() = 0;
};

class ConcreteComponent:public Component
{
public:
  ConcreteComponent():Component() { };
  virtual ~ConcreteComponent() { };
public:
  virtual void operation();
};
void ConcreteComponent::operation()
{
  cout<<"ConcreteComponent\n";
}


class Decorator:public Component
{
public:
  Decorator(Component* comp):component(comp) { };
  virtual ~Decorator() { };
private:
  Component* component;
public:
  void setComponent(Component* comp){ component = comp;};
  virtual void operation();
};

void Decorator::operation()
{
  if(NULL != component){
    component->operation();
  }
}

class ConceteDecoratorA:public Decorator
{
public:
  ConceteDecoratorA();
  virtual ~ConceteDecoratorA();
public:
  virtual void operation();
};
void ConceteDecoratorA::operation()
{
  cout<<"ConceteDecoratorA\n";
}


class ConceteDecoratorABpublic Decorator
{
public:
  ConceteDecoratorB();
  virtual ~ConceteDecoratorB();
public:
  virtual void operation();
};
void ConceteDecoratorB::operation()
{
  cout<<"ConceteDecoratorA\n";
}



int main()
{
  Component* p1 = new ConcreteComponent();
  Component* p2 = new ConceteDecoratorA();
  Component* p3 = new ConceteDecoratorB();



}
