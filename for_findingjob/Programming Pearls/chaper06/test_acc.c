/*
 * =====================================================================================
 *
 *       Filename:    test_acc.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-21 13:39:46
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>
#include <time.h>

void test_fun(int n, int testnums)
{
  /* double a1,b1; */
  double a1,b1;
  time_t t;
  int i,j;
  a1 = b1 = 10.123456789;
  
  t = clock();
  for(j = 0; j < testnums; ++j){
    for(i = 0; i < n; ++i){
      a1 = a1+b1;
      a1 = 10.123456789;
      b1 = 10.123456789;
    }
  }
  t = clock() - t;
  printf("%ld\n",t);
}

main(int argv, char* args[])
{
  test_fun(10000,10000);
}
