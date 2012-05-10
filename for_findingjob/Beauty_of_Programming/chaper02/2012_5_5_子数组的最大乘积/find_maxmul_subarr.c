/*
 * =====================================================================================
 *
 *       Filename:    find_maxmul_subarr.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年05月05日 16时08分07秒
 *       Compiler:    gcc
 *       Description: 
 *             题目：给定一个长度为N的整数数组，只容许乘法，不能用除法
 *                   计算任意(N-1)个数的组合中乘积最大的一组，并写出算
 *                   法的时间复杂度
 *
 * ======================================================================================
 */
#include <stdio.h>

//方法1: 利用空间换时间的方法
long find_max_mul_1(int *a, size_t n){
  int i;
  long all_mul = 1;
  long max = 1<<(sizeof(long)*8 - 1);
//  printf("%d",max);
  for(i = 0; i < n; ++i){
    all_mul *= a[i];
  }
  for(i = 0; i < n; ++i){
    if(max<all_mul/a[i]) max = all_mul/a[i];
  }
  return max;
}
#ifndef _FIND_MAX_MUL_2_H
//方法2：利用正负号和0来计算
long find_max_mul_2(int *a, size_t n){
  int i;
  size_t pos = 0;
  size_t neg = 0;
  size_t zero = 0;
  long res = 0;
  long min_pos = ~(1<<31);
  long max_neg = 1;
  size_t min_pos_i;
  size_t max_neg_i;
  size_t zero_i;
  for(i = 0; i < n; ++i){
    if(a[i]<0) {
      ++neg;
      if(max_neg>a[i]) max_neg = a[i],max_neg_i = i;
    }

    else if(a[i]>0){
      ++pos;
      if(min_pos<a[i]) min_pos = a[i],min_pos_i = i;
    }
    else ++zero, zero_i = i;
  }
  if(zero >1) res = 0;
  else if(zero==1)
    if(neg%2==0){
  //有偶数的负数,del min pos 
     
  }
  else {
  //基数个负数, del max neg  
  }

}
#endif
int main()
{
  int a[10] = {-1,3,3,4,-5,6,7,8,9,10};
//  long max = 1<<(sizeof(long)*8-1);
//  printf("%d",max);
  printf("%d",find_max_mul(a,10));
}
