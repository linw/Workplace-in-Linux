/*
 * =====================================================================================
 *
 *       Filename:    screen_test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月29日 22时16分39秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "Screen.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  Screen s("king",0,0);
  s.move(4,9).set("linwei").display(cout);
  return 0;
}

