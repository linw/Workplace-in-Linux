/*
 * =====================================================================================
 *
 *       Filename:    maxsum.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-25 8:42:04
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 寻找最大子向量
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
long maxsum1(const int *num, const size_t n)
{
  int i,j,k;
  long sum = LONG_MIN;
  long tmp;
  for(i = 0; i < n; ++i){
    for(j = i; j < n; ++j){
      tmp = 0;
      for(k = i; k <= j; ++k){
        tmp += num[k];
      }
      if(tmp > sum){
        sum = tmp;
      }
    }
  }
  return sum;
}

long maxsum2(const int *num, const size_t n)
{
  int i,j;
  long sum = LONG_MIN;
  long tmp;
  for(i = 0; i < n; ++i){
    tmp = 0;
    for(j = i; j < n; ++j){
      tmp += num[j];
      sum = sum>tmp?sum:tmp;
    }
  }
  return sum;
}

// 线性算法,动态规划
long maxsum3(const int *num, const size_t n)
{
  long all;
  long start;
  int i;
  all= start = num[n-1];
  for(i = n-2; i >= 0; --i){
    start = num[i]>(num[i]+start)? num[i]:(num[i]+start);
    all = start>all? start:all;
  }
  return all;
}

long maxsum4(const int *num, const size_t n)
{
  int i;
  long all,start;
  all = start = num[n-1];
  for(i = n-2; i >=0; --i){
    if(num[i] < 0){
      start = 0;
    }
    start += num[i];
    if(start > all){
      all = start;
    }
  }
  return all;
}


void count_time(int switch_flag, int n, int num_test)
{
  int *num;
  int i,j;
  long maxsum;
  time_t t;
  num = (int*)malloc(sizeof(int)*n);
  for(i = 0; i < n; ++i){
    num[i] = i;
  }
  t = clock();

  for(i = 0; i < num_test; ++i){
    switch(switch_flag){
      case 0: maxsum1(num,n);break;
      case 1: maxsum2(num,n);break;
      case 2: maxsum3(num,n);break;
    }
  }
  t = clock() - t;
  printf("%d %d %d %lf\n",switch_flag,n,num_test,(double)1000000*t/num_test);
}



main()
{
  // int num[10] = {1,2,-2,3,4,-5,8,1,9,10};
  // long maxsum;
  // maxsum = maxsum1(num,10);
  // maxsum = maxsum2(num,10);
  // maxsum = maxsum3(num,10);
  // printf("%ld\n", maxsum);
  count_time(0,1000,1000);
  // count_time(1,100,1000);
  count_time(2,1000,1000);
}
