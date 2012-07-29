/*
 * =====================================================================================
 *
 *       Filename:    abstract_factory.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-11 17:22:16
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */

#include <iostream>
using std::cout;
using std::endl;
class Operation
{
public:
  Operation(const double _numberA = 0, const double _numberB = 0):numberA(_numberA),numberB(_numberB){};
  virtual ~Operation(){};
private:
  double numberA;
  double numberB;
public:
  const double getNumberA() const{ return numberA; };
  double getNumberA() { return numberA; };
  void setNumberA(const double _numberA) { numberA = _numberA; };

  const double getNumberB() const { return numberB; };
  double getNumberB() { return numberB; };
  void setNumberB(const double _numberB) { numberB = _numberB; };
  virtual double getResult() const = 0;
};
class AddOperation:public Operation
{
public:
  AddOperation(const double _numberA=0, const double _numberB=0):Operation(_numberA,_numberB){ };
public:
  double getResult() const { return getNumberA()+getNumberB(); };
};
class SubOperation:public Operation
{
public:
  SubOperation(const double _numberA=0, const double _numberB=0):Operation(_numberA,_numberB) { };
public:
  double getResult() const { return getNumberA() - getNumberB();};
};

class OperationFactory
{
public:
  enum OperationName { ADD=0, SUB=1};
public:
  static Operation* createOperator(OperationName operate);
};

Operation* OperationFactory::createOperator(OperationFactory::OperationName operate)
{
  Operation* oper = NULL;
  switch(operate){
    case OperationFactory::ADD:
      oper = new AddOperation();
      break;
    case OperationFactory::SUB:
      oper = new SubOperation();
      break;
  }
  return oper;
}

int main()
{
  // AddOperation a(10,26);
  // SubOperation b(10,26);
  // cout<<a.getResult();
  // cout<<b.getResult();
  Operation* a = OperationFactory::createOperator(OperationFactory::SUB);
  a->setNumberA(10);
  a->setNumberB(20);
  cout<<a->getResult()<<endl;
  return 0;
}
