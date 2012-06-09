/*
 * =====================================================================================
 *
 *       Filename:    find_all.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年05月14日 15时49分41秒
 *       Last Edit:   2012-5-14  15:50:37
 *       Compiler:    gcc
 *       Description:
 *               题目：对于一个正整数，能否表示为一个连续自然数的加和，输出所有可能的序列
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
void print_num(unsigned int start,unsigned int end)
{
  assert(start<=end);
  for(;start<=end;++start)
    printf("%d ",start);
  printf("\n");
}
// solutation1: 穷举法
bool print_all_1(unsigned int a){
  int i,j;
  int sum;
  bool flag = false;
  for(i = 1; i<=a/2+1;++i){
    sum = 0;
    for(j = i; j <= a/2+1; ++j){
      sum += j;
      if(sum == a){
        flag = true;
        print_num(i,j);
        break;
      }
    }
  }
  return flag;
}
// solutation2: 转化成为公式进行求解
// x+(x+1)+...+(x+k) = m
// m = (k+1)x+(1+k)k/2
// x = (2m-k(k+1))/(2(k+1))
bool is_verify(unsigned int m, unsigned int x, unsigned int k){
  if((2*m-k*(k+1)) % (2*(k+1)) == 0)
    if(x == (2*m-k*(k+1))/(2*(k+1)))
      return true;
  return false;
}
bool print_all_2(unsigned int a){
  unsigned int x,k;
  bool flag = false;
  for(x = 0;x<=a/2+1;++x){
    for(k = 0;k<=a/2+1-x;++k){
      if(is_verify(a,x,k)){
        print_num(x,x+k);
        flag = true;
        break;
      }
    }
  }
  return flag;
}

main()
{
  if(!print_all_2(100))
    printf("can't find");
}
