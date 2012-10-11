/*
 * =====================================================================================
 *
 *       Filename:    increase.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-08 20:05:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int
main(void)
{
  int a;
  a = 4;
  a += (++a);
  a += (a++);
  // (++a) += (a++); // gcc 下error, ++a不是左值... 但好像应该是
  //  (a++) += a; // error , 必须是左值

  printf("%d\n", a);
  return 0;
}
