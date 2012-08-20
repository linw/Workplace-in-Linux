/*
 * =====================================================================================
 *
 *       Filename:    memento_method.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-15 15:17:57
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 备忘录模式:在不破坏封装性的前提下,捕获一个对象的内部状态,并在该对象外保存这个状态
 *                             这样以后就可以将该对象恢复到原先保存的状态.
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

// 备忘录类
class Memento
{
public:
  Memento() { name = ""; saying = "";}
  Memento(const string _name, const string _saying){ name = _name; saying = _saying; }
  Memento(const Memento& _m){name = _m.name; saying = _m.saying; }
  virtual ~Memento(){}
private:
  string name;
  string saying;
public:
  string getName() { return name; }
  const string getName() const { return (const string)name; }
  string getSaying() { return saying; }
  const string getSaying() const { return (const string)saying;}
};

// 发起人类(这种模式就是要保存发起人的过往状态)
class Originator
{
public:
  Originator(){ name = ""; saying = ""; }
  Originator(const Originator& _o){ name = _o.name; saying = _o.saying; }
  virtual ~Originator(){ name = ""; saying = "";}
private:
  string name;
  string saying;
public:
  string getName() { return name; }
  const string getName() const { return (const string)name; }
  void setName(const string _name) { name = _name; }
  string getSaying() { return saying; }
  const string getSaying() const { return (const string)saying;}
  void setSaying(const string _saying) { saying = _saying; }
  Memento createMemento() { return Memento(name,saying); }
  void setMemento(Memento _m) { name = _m.getName(); saying = _m.getSaying(); }
  void show() { cout<<"name:"<<name.c_str()<<"   "<<"saying:"<<saying.c_str()<<endl; }
};






// 管理者类
class Caretaker
{
public:
  Caretaker(){ }
  Caretaker(const Caretaker& _c){ memento = _c.memento; }
  virtual ~Caretaker(){}
private:
  Memento memento;
public:
  Memento getMemento() { return memento; }
  const Memento getMemento() const { return memento;}
  void setMemento(const Memento& _memento) { memento = _memento; }
};

int main(int argv, char* args[])
{
  Originator o;
  o.setName("linwei");
  o.setSaying("I love you!");
  o.show();
  Caretaker c;
  c.setMemento(o.createMemento());
  o.setName("chihao");
  o.show();
  o.setMemento(c.getMemento());
  o.show();
  return 0;
}
