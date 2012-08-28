/*
 * =====================================================================================
 *
 *       Filename:    state.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-10 22:34:32
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 状态模式:当一个对象的内在状态改变时容许改变其行为,这个对象看起来像是改变了其类
 *                    就是通过继承一个状态类,然后在每个类中加入简单判断,通过判断转换成其他状态.
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;

class Context;
class State;
class ConcreteStateA;
class ConcreteStateB;

class State
{
public:
  State(){}
  State(const State& _s){}
  virtual ~State(){}
public:
  virtual void handle(Context* context) = 0;
  virtual void print() = 0;
};

class Context
{
public:
  Context(State* _state){
    state = _state;
    i = 0;
  }
  Context(const Context& _c){
    state = _c.state;
    i = _c.i;
  }
  virtual ~Context(){}
public:
  State *state;
  int i;
public:
  State* getState(){
    return state;
  }
  void setState(State* _s){
    state = _s;
  }
  void request(){
    state->handle(this);
    state->print();
  }
};




class ConcreteStateA:public State
{
public:
  ConcreteStateA(){}
  ConcreteStateA(const ConcreteStateA& _csa){}
  virtual ~ConcreteStateA(){}
public:
  void handle(Context* context);// {
  //   if(context->i != 0){
  //     context->setState(new ConcreteStateB());
  //   }
  //   else if(context->i == 0 && context->getState() == NULL){
  //     context->setState(new ConcreteStateA());
  //   }
  //   ++(context->i);
  // }
  void print(){
    cout<<"ConcreteStateA"<<endl;
  }
};

class ConcreteStateB:public State
{
public:
  ConcreteStateB(){}
  ConcreteStateB(const ConcreteStateB& _csb){}
  virtual ~ConcreteStateB(){}
public:
  void handle(Context* context);// {
  //   if(context->i != 1){
  //     context->setState(new ConcreteStateA());
  //   }
  //   else if(context->i == 1 && context->getState() == NULL){
  //     context->setState(new ConcreteStateB());
  //   }
  //   --(context->i);
  // }
  void print(){
    cout<<"ConcreteStateB"<<endl;
  }
};

void ConcreteStateA::handle(Context* context)
{
  if(context->i != 0){
    context->setState(new ConcreteStateB());
  }
  else if(context->i == 0 && context->getState() == NULL){
    context->setState(new ConcreteStateA());
  }
  ++(context->i);
}

void ConcreteStateB::handle(Context* context)
{
  if(context->i != 1){
    context->setState(new ConcreteStateA());
  }
  else if(context->i == 1 && context->getState() == NULL){
    context->setState(new ConcreteStateB());
  }
  --(context->i);
}



int main(int argv, char * args[])
{
  Context c = Context(new ConcreteStateA());
  c.request();
  c.request();
  //  c.setState(new ConcreteStateB());
  c.request();
  c.request();
  return 0;
}
