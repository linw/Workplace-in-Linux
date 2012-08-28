/*
 * =====================================================================================
 *
 *       Filename:    calcuate_sum.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-11 11:04:53
 *       Last Edit:
 *       Compiler:    gcc
 *       Description:
 *              题目：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case
 *                   等判断语句以及条件判断语句A?B:C
 *              理解：利用类的构造函数实现，使用c++。使用c似乎无法实现该过程
 *              2012-6-11 13:55:33 可以利用c实现，主要使用到了函数指针
 *
 * =====================================================================================
 */
#include <stdio.h>
// 解决方法1：
class Cal{
 private:
  static long sum;
  static int num;
 public:
  Cal(){
    sum += num++;
  }
  static void reset(){
    sum = num = 0;
  }
  static long get_sum(){
    return sum;
  }
};
long Cal::sum = 0;
int Cal::num = 1;


// 方法2:
class A;
A *array[2];
class A{
 public:
  virtual long sum(int n){ return 0;}
};

class B:public A{
 public:
  virtual long sum(int n){
    return array[!!n]->sum(n-1) +n; // 在这里判断是交由A还是B
  }
};

long cal_sum(int n)
{
  A a;
  B b;
  array[0] = &a;
  array[1] = &b;
  return array[1]->sum(n);
}


// 方法3：也可以用函数指针实现
long (*cal_fun[2])(int);
long cal_1(int n)
{
  return 0;
}
long cal_2(int n)
{
  return cal_fun[!!n](n-1)+n;
}

long cal_sum_1(int n)
{
  cal_fun[0] = cal_1;
  cal_fun[1] = cal_2;
  return cal_fun[1](n);
}


int main()
{
  Cal *p;
  p = new Cal[100];
  printf("%d\n",Cal::get_sum());
  delete[] p;
  printf("%d\n",cal_sum(100));
  printf("%d\n",cal_sum_1(1));
  return 0;
}
