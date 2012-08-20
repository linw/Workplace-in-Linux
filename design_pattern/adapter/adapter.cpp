/*
 * =====================================================================================
 *
 *       Filename:    adapter.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-14 16:48:51
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 适配器模式: 把一个类的接口转化成用户希望的另一个接口,可以克服接口的不统一的缺点   
 *                    在双方都不好改变的情况下使用适配器模式                           
 * =====================================================================================
 */
#include<iostream>
using namespace std;


class Target
{
public:
  Target(){}
  Target(const Target& t){}
  virtual ~Target(){}
public:
  virtual void request() = 0;
};




class Adaptee
{
public:
  Adaptee(){}
  Adaptee(const Adaptee& _a){}
  virtual ~Adaptee(){}
public:
  void specificRequest();
};

void Adaptee::specificRequest()
{
  cout<<"你好,世界!"<<endl;
}



class Adapter:public Target
{
public:
  Adapter(){ adaptee = new Adaptee();}
  Adapter(const Adapter& _a){ adaptee = _a.adaptee;}
  virtual ~Adapter(){ 
    if(NULL != adaptee){
      delete adaptee;
    }
    adaptee = NULL;
  }
private:
  Adaptee* adaptee;
public:
  void request();
};
void Adapter::request()
{
  if(NULL == adaptee){
    cout<<"init adaptee now!"<<endl;
  }
  adaptee->specificRequest();
}




int main(int argv, char* args[])
{
  Target* p = new Adapter();
  p->request();
  return 0;
}
