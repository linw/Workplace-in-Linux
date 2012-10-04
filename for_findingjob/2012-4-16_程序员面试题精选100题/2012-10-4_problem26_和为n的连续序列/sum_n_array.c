/*
 * =====================================================================================
 *
 *       Filename:    sum_n_array.c
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

void print_array(const unsigned int *array, int begin, int end){
  assert(array);
  int i;
  for(i = begin; i <= end; ++i){
    printf("%d",array[i]);
  }
  printf("\n");
}

void
print_all_sumN(const unsigned int *array, int len, unsigned int sum)
{
  assert(array&&len>=0);
  int _sum;
  int i;
  int begin;
  int end;
  int flag;
  begin = 0;
  end = 0;
  _sum = 0;
  flag = 0;
  while(begin <= end && end < len){
    if(flag == 0){
      _sum += array[end];
    }else {
      _sum -= array[begin-1];
    }
    if(sum == _sum){
      print_array(array, begin, end);
      ++end;
      flag = 0;
      continue;
    }
    else if(sum < _sum){
      ++begin;
      flag = 1;
    }
    else {
      ++end;
      flag = 0;
    }
  }
}

int
main(void)
{
  int a[] = {1,2,3,4,5,6,7,8,9,10,15,15,15};
  print_all_sumN(a, 13, 15);
  exit(0);
}
