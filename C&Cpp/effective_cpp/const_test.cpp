/*
 * =====================================================================================
 *
 *       Filename:    const_test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-29 14:11:42
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argv, char* args[])
{
  vector<int> ivec;
  ivec.push_back(1);
  ivec.push_back(2);
  const vector<int>::iterator iter = ivec.begin();
  vector<int>::const_iterator citer;
  *citer = 10;
  return 0;
}
