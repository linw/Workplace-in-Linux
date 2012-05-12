/*
 * =====================================================================================
 *
 *       Filename:    split_array_to_equal_subarray.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-11 14:46:18
 *       Compiler:    gcc
 *       Description: 有一个无序的，元素个数为2n的正整数数组，要求：如何能把这个数组分割为元素个数为n
 *                    的两个数组，并使两个子数组的和最接近
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// solution1: 利用动态规划，其实只要计算n个数组的和和sum/2比较就可以
void split_array_to_equal_subarray_1(int *a, int n, int *sub_1,int *sub_2){
  long sum;
  int i,j;
  sum = 0;
  for(i = 0; i < n; ++i)
    sum += a[i];
  sum /= 2;

}
main()
{
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  int *sub_1;
  int *sub_2;
  sub_1 = (int*)malloc(sizeof(int)*5);
  sub_2 = (int*)malloc(sizeof(int)*5);
  split_array_to_equal_subarray_1(a,10,sub_1,sub_2);
  free(sub_1);
  free(sub_2);
}
