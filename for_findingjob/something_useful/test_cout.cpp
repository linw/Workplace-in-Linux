/*
 * =====================================================================================
 *
 *       Filename:    test_cout.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-10 10:35:19
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;
using std::flush;
int f(int & i)
{
  i++;
  return i;
}

int main(int argc, char* argv[])
{
  int x = 10;
  cout<<x<<'\t'<<endl<<f(x)<<'\t'<<endl<<x<<endl;
  return 0;
}
