/*
 * =====================================================================================
 *
 *       Filename:    my_power.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-08 10:38:38
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double my_power(double base, int exponent)
{
  int i;
  int flag; // 用于标示exponent正负
  int flag1 = 0;
  double result;
  flag = 0; // 表示正值
  if(exponent == 0){
    return 1.0;
  }
  if(exponent < 0){
    flag = 1;
    exponent = -exponent;
  }
  if(exponent&1) flag1 = 1;
  result = my_power(base, exponent>>1);
  result *= result;
  if(flag1){
    result = result*base;
  }
  if(flag){
    result = 1.0/result;
  }
  return result;
}


int
main(void)
{
  printf("%lf\n",my_power(0.25,-5));
  return 0;
}

