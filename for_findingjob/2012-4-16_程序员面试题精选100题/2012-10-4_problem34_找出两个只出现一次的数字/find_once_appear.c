/*
 * =====================================================================================
 *
 *       Filename:    find_once_appear.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 16:12:44
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int find_first_1(int a)
{
  int i;
  i = 0;
  while(((a&1) == 0) && (i < 32)){
    ++i;
    a = a>>1;
  }
  return i;
}

int nbit_is_1(int a, int n)
{
  return a&(1<<n);
}

void find_once_appear(const int *array, const int len, int *a, int *b)
{
  int sum;
  int i;
  int n;
  sum = 0;
  for(i = 0; i < len; ++i){
    sum ^= array[i];
  }
  n = find_first_1(sum);
  *a = *b = 0;
  for(i = 0; i < len; ++i){
    if(nbit_is_1(array[i],n)){
      *a ^= array[i];
    }
    else {
      *b ^= array[i];
    }
  }
}

int
main(void)
{
  //  printf("%d\n",find_first_1(17));
  int a[] = {-1,-1,-2,-3,-2,-3,-4,-5,-6,-6,-7,-7,-0,-0,-1,-1};
  int k1,k2;
  find_once_appear(a,16,&k1,&k2);
  printf("%d  %d\n",k1,k2);
  return 0;
}

