/*
 * =====================================================================================
 *
 *       Filename:    test_operator.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-03 18:58:35
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
main()
{
  int a = 1, b = 2, m = 0,n = 0,k;
  k = (n=b>a)&&(m=b<a);
  k = n=b>a;
  printf("%d,%d\n",k,m);
}
