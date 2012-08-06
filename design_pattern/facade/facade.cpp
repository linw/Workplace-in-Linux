/*
 * =====================================================================================
 *
 *       Filename:    facade.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-04 20:49:55
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 外观模式: 就是定义一个一致的界面,统一的方法来管理子系统中的功能,使得子系统更加
 *                             容易使用
 *
 * =====================================================================================
 */

#include <iostream>
using std::endl;
using std::cout;

class SubSystemOne
{
public:
  SubSystemOne(){};
  SubSystemOne(const SubSystemOne& _sso){};
  virtual ~SubSystemOne(){};
public:
  void MethodOne();
};

void SubSystemOne::MethodOne()
{
  cout<<"MethodOne!"<<endl;
}



class SubSystemTwo
{
public:
  SubSystemTwo(){};
  SubSystemTwo(const SubSystemTwo& _sst){};
  virtual ~SubSystemTwo(){};
public:
  void MethodTwo();
};

void SubSystemTwo::MethodTwo()
{
  cout<<"MethodTwo!"<<endl;
}

class SubSystemThree
{
public:
  SubSystemThree(){};
  SubSystemThree(const SubSystemThree& _sst){};
  virtual ~SubSystemThree(){};
public:
  void MethodThree();
};

void SubSystemThree::MethodThree()
{
  cout<<"MethodThree!"<<endl;
}



// class Facade
class Facade
{
private:
  SubSystemOne* one;
  SubSystemTwo* two;
  SubSystemThree* three;
public:
  Facade(){
    one = new SubSystemOne();
    two = new SubSystemTwo();
    three = new SubSystemThree();
  }
  Facade(const Facade& _fac){
    one = _fac.one;
    two = _fac.two;
    three = _fac.three;
  }
  virtual ~Facade(){
    delete one;
    delete two;
    delete three;
  }
public:
  void MethodA();
  void MethodB();
};

void Facade::MethodA()
{
  if(one != NULL){
    one->MethodOne();
  }
  if(three != NULL){
    three->MethodThree();
  }
  if(two != NULL){
    two->MethodTwo();
  }
}

void Facade::MethodB()
{
  if(one != NULL){
    one->MethodOne();
  }
  if(two != NULL){
    two->MethodTwo();
  }
  if(three != NULL){
    three->MethodThree();
  }
}



int main()
{
  Facade *p = new Facade();
  cout<<"====================start Facade MethodA===================="<<endl;
  p->MethodA();
  cout<<endl;
  cout<<"====================start Facade MethodB===================="<<endl;
  p->MethodB();
  delete p;
}
