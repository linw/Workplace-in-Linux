/*
 * =====================================================================================
 *
 *       Filename:    find_two.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-11 14:56:44
 *       Last Edit:   2012-6-11 14:56:50
 *       Compiler:    gcc
 *       Description:
 *              题目：在排序数组中找到和为指定值的两个数,要求时间复杂度为O(n)
 *              理解：主要利用了数组是排好序的条件
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_two(const int *array, const int n, const value, int *a, int *b)
{
  int i,j;
  for(i = 0, j = n-1; i<j;){
    if(array[i] + array[j]>value){
      --j;
    }
    else if(array[i] + array[j]<value){
      ++i;
    }
    else {
      *a = array[i];
      *b = array[j];
      return 1;
    }
  }
  if(i>=j)
    return 0;
}


main()
{
  int array[] = {1,2,3,4,5,6,7,8,9};
  int a,b;
  if(find_two(array,9,15,&a,&b))
    printf("%d,%d\n",a,b);
  else
    printf("can't find!\n");
}
