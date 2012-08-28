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
 public:
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
  ConceteDecoratorA(Component* comp):Decorator(comp){};
  virtual ~ConceteDecoratorA(){};
public:
  virtual void operation();
};
void ConceteDecoratorA::operation()
{
  component->operation();
  cout<<"ConceteDecoratorA\n";
}


class ConceteDecoratorB:public Decorator
{
public:
  ConceteDecoratorB(Component* comp):Decorator(comp){};
  virtual ~ConceteDecoratorB(){};
public:
  virtual void operation();
private:
  void AddedBehavior();
};

void ConceteDecoratorB::operation()
{
  component->operation();
  cout<<"ConceteDecoratorA\n";
  AddedBehavior();
}
void ConceteDecoratorB::AddedBehavior()
{
  cout<<"AddedBehavior\n";
}



int main()
{
  Component* p1 = new ConcreteComponent();
  Component* p2 = new ConceteDecoratorA(p1);
  Component* p3 = new ConceteDecoratorB(p2);
  Component* p4 = new ConceteDecoratorB(p3);
  //  p1->operation();
  //  p2->operation();
  //  p3->operation();
  p4->operation();
}
