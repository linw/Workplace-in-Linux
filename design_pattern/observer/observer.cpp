/*
 * =====================================================================================
 *
 *       Filename:    observer.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-05 23:11:40
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 观察者模式:定义了一种一对多的关系,在主体状态发生变化的时候,会通知所有的观察者对象
 *                             从而更新他们自己的状态.
 * =====================================================================================
 */
#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;

// 被通知者
class Observer
{
public:
  Observer(){}
  Observer(const Observer& _o){}
  virtual ~Observer(){}
public:
  virtual void update() = 0;
};


//通知者
class Subject
{
public:
  Subject(){
    observers.clear();
  }
  Subject(const Subject& _s){
    observers = list<Observer*>(_s.observers);
  }
  virtual ~Subject(){
    observers.clear();
  }
private:
  list<Observer*> observers;
public:
  void attach(Observer* observer);
  void detach(Observer* observer);
  void notify();
};

void Subject::attach(Observer* observer)
{
  for(list<Observer*>::iterator iter = observers.begin();
      iter != observers.end();
      ++iter){
    if(observer == *iter)
      return;
  }
  observers.push_back(observer);
}

void Subject::detach(Observer* observer)
{
  for(list<Observer*>::iterator iter = observers.begin();
      iter != observers.end();
      ++iter){
    if(observer == *iter){
      iter = observers.erase(iter);
      return;
    }
  }  
}

void Subject::notify()
{
  for(list<Observer*>::iterator iter = observers.begin();
      iter != observers.end();
      ++iter){
    (*iter)->update();
  }
}




class ConcreteObserver:public Observer
{
public:
  ConcreteObserver(const string _s){ i = 0; name = _s;}
  ConcreteObserver(const ConcreteObserver& _co){ i = _co.i; name = _co.name;}
  virtual ~ConcreteObserver(){};
private:
  int i;
  string name;
public:
  void update(){
    ++i;
    cout<<"name is:"<<name<<"  i is:"<<i<<endl;
  }
};



int main()
{
  ConcreteObserver a = ConcreteObserver("linwei");
  ConcreteObserver b = ConcreteObserver("chihao");
  Subject p;
  p.attach(&a);
  p.attach(&b);
  
  for(int i = 0; i < 10; ++i){
    p.notify();
    cout<<endl;
  }
  return 0;
}
