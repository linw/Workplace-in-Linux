/*
 * =====================================================================================
 *
 *       Filename:    heap_fun.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-28 09:59:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;




int main()
{
  map<string,int> mm;
  mm["linwei"] = 1;
  mm["chihao"] = 2;
  cout<<mm["linwei"]<<endl;
  mm.insert(map<string,int>::value_type("king",2));
  cout<<mm["king"]<<endl;
  return 0;
}

