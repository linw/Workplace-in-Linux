/*
 * =====================================================================================
 *
 *       Filename:    proxy.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-31 20:57:33
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 代理模式，正真意义上的主体和代理有相同的接口，利用代理完成真实主体的功能
 *
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;

class Subject
{
public:
  Subject(){};
  virtual ~Subject(){};
public:
  virtual void request() = 0;
};

class RealSubject:public Subject
{
public:
  RealSubject(){};
  virtual ~RealSubject() {};
public:
  void request();
};
void RealSubject::request()
{
  cout<<"RealSubject request!"<<endl;
}

class Proxy:public Subject
{
public:
  Proxy():realSubject(NULL){};
  virtual ~Proxy(){};
private:
  RealSubject * realSubject;
public:
  void request();
};

void Proxy::request()
{
  if(NULL == realSubject){
    realSubject = new RealSubject();
  }
  realSubject->request();
}

int main()
{
  Proxy *p = new Proxy();
  p->request();
  delete p;
  return 0;
}
