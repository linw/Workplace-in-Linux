/*
 * =====================================================================================
 *
 *       Filename:    array_shift.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-11 13:48:15
 *       Compiler:    gcc
 *       Description:
 *              设计算法，把一个含有N个元素的数组循环向右移动K位，要求时间复杂度O(N)，且只容许使用两个附加变量
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// solutaion1: The most simple solutaion, but time complexity is O(N*K)
void right_shift_1(int *a, unsigned int n,unsigned int k){
  int i,j;
  while(k--){
    j = a[n-1];
    for(i = n-1; i >0; --i){
      a[i] = a[i-1];
    }
    a[0] = j;
  }
}

// solutaion2: a O(N) time complexity solution
// (ab) --- (ba) ===  ~(~a~b) == ba
void reverse(int *a,unsigned int start,unsigned int end){
  assert(end>=start);
  for(;start<end;++start,--end){
    a[start] = a[start]+a[end];
    a[end] = a[start]-a[end];
    a[start] = a[start]-a[end];
  }
}
void right_shift_2(int *a, unsigned int n,unsigned int k){
  assert(k<=n&&k>=0);
  //  int i,j;
  //  for(i = 0; i < n-k-i; ++i){
  //  a[i] = a[i]+a[n-k-i-1];
  //   a[n-k-i-1] = a[i]-a[n-k-i-1];
  //  a[i] = a[i]-a[n-k-i-1];
  // }
  // for(i = n-k,j=0;i<n-j;++i,++j){
  //  a[i] = a[i]+a[n-j-1];
  //  a[n-j-1] = a[i]-a[n-j-1];
  //  a[i] = a[i]-a[n-j-1];
  // }
  //  for(i = 0; i < n-i; ++i){
  //   a[i] = a[i]+a[n-i-1];
  //  a[n-i-1] = a[i]-a[n-i-1];
  //  a[i] = a[i]-a[n-i-1];
  //  }
  reverse(a,0,n-k-1);
  reverse(a,n-k,n-1);
  reverse(a,0,n-1);
}

main()
{
  int a[] = {1,2,3,4,5,6,7,8,9,0};
  int i;
  right_shift_2(a,10,5);
  for(i = 0; i < 10; ++i)
    printf("%d ",a[i]);
}
