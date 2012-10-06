/*
 * =====================================================================================
 *
 *       Filename:    sum_of_1.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-06 11:57:16
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 这种方法会造成死循环
unsigned int sum_of_1(int num)
{
  int count;
  count = 0;
  while(num){
    if(num&1){
      ++count;
    }
    num = num>>1;
  }
  return count;
}

unsigned int sum_of_1_a(int num)
{
  int count;
  unsigned int flag;
  count = 0;
  flag = 1;
  while(flag){
    if(num&flag){
      ++count;
    }
    flag = flag<<1;
  }
  return count;
}

unsigned int sum_of_1_b(int num)
{
  int count;
  count = 0;
  while(num){
    ++count;
    num = num&(num-1);
  }
  return count;
}

int
main(void)
{
  printf("%d\n",sum_of_1_b(-1));
  return 0;
}
