/*
 * =====================================================================================
 *
 *       Filename:    sum_float.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-21 13:39:46
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>

main(int argv, char* args[])
{
  float array[1000];
  int i,j;
  float sum;
  sum = 0;
  for(i = 0; i < 1000; i += 2){
    array[i] = 0.01;
  }
  for(i = 1; i < 1000; i += 2){
    array[i] = 1000;
  }
  for(i = 0; i < 1000; i += 2){
    sum += array[i];
  }
  for(i = 1; i < 1000; i += 2){
    sum += array[i];
  }
  printf("%f\n",sum);
}
