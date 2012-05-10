/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月26日 11时18分43秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "person.h"
using namespace std;
int main()
{
  Person a;
  a.print_info();
  a.modify_info("king","xidian");
  a.print_info();
  Person b("king","taiyuan");
  b.print_info();
  return 0;
}
