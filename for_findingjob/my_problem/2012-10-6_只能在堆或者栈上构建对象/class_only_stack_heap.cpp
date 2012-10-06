/*
 * =====================================================================================
 *
 *       Filename:    class_only_stack_heap.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-06 22:49:45
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
using namespace std;

class OnlyHeap
{
public:
  OnlyHeap(){ cout<<"OnlyHeap constructor"<<endl;}
  void destroy(){ delete this; }
private:
  ~OnlyHeap(){};
};

class OnlyStack
{
private:
  void* operator new(size_t);
  void operator delete(void*);
  void operator delete[](void*);
};

int
main(void)
{
  OnlyHeap* a = new OnlyHeap;
  int i;
  //  OnlyStack* k = new OnlyStack;
  a->destroy();
  return 0;
}
