/*
 * =====================================================================================
 *
 *       Filename:    FinalClass.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 16:12:44
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <iostream>
using namespace std;

class FinalClass
{
private:
  FinalClass(){};
  ~FinalClass(){};
};

class SubClass:public FinalClass
{
};

template <typename T> class MakeFinal
{
  friend T;
private:
  MakeFinal() {}
  ~MakeFinal() {};
};

class FinalClass2: virtual public MakeFinal<FinalClass2>
{
public:
  FinalClass2(){}
  ~FinalClass2(){}
};


int
main(void)
{
  //  FinalClass2 k;
  return 0;
}
