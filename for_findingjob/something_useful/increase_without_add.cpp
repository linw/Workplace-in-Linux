/*
 * =====================================================================================
 *
 *       Filename:    increase_without_add.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-08 22:45:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 对一个变量进行自增的操作而不使用+号
 * =====================================================================================
 */
#include <iostream>
using std::endl;
using std::cout;
using std::hex;

int main()
{
  int x = 111;
  int y = 1;
  while((x&y) == y){
    x = (x&(~y));
    y = y<<1;
  }
  x = x|y;
  cout<<x<<endl;
  return 0;
}
