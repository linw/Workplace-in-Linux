#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
  Base() { };
  virtual ~Base();
};
Base::~Base()
{
  cout<<"release Base"<<endl;
}

class BaseA:public Base
{
public:
  BaseA() { };
  ~BaseA();

  /* data */
};
BaseA::~BaseA()
{
  cout<<"release BaseA"<<endl;
}

class BaseB:public BaseA
{
public:
  BaseB() { };
  ~BaseB();
};

BaseB::~BaseB()
{
  cout<<"release BaseB"<<endl;
}

int main()
{
  BaseA* p;
  p = new BaseB();
  delete p;
  cout<<"Base size: "<<sizeof(Base)<<endl;
  cout<<"BaseA size:"<<sizeof(BaseA)<<endl;
  cout<<"BaseB size:"<<sizeof(BaseB)<<endl;
  return 0;
}