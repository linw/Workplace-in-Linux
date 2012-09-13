/*
 * =====================================================================================
 *
 *       Filename:    kmp.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-12 15:35:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
#include <assert.h>
using namespace std;

int* compute_next(const char *p, int *next)
{
  int i,j;
  int len;
  len = strlen(p);
  assert(p&&next);
  
}


int main(int argv, char* args[])
{
  char a[] = "ababababca";
  int pi[11];
  compute_prefix_function(a,pi,11);
  for(int i = 0; i < 11; ++i){
    cout<<pi[i]<<",";
  }
  cout<<endl;
  return 0;
}

