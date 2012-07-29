/*
 * =====================================================================================
 *
 *       Filename:    bsearch.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-24 16:34:41
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int count = 0;
// 成功返回位置，失败返回-1
// 数组元素递增
int my_bsearch(const int *array, const size_t n, const int k)
{
  int start, end, mid;
  assert(n>0);
  start = 0;
  end = n - 1;  
  while(end>=start){
    mid = (end + start)/2;
    if(/*count++,*/array[mid] > k){
      end = mid - 1;
      // printf("start:%d; end:%d\n",start,end);
      continue;
    }
    else if(/*count++,*/array[mid] < k){
      start = mid + 1;
      // printf("start:%d; end:%d\n",start,end);
      continue;
    }
    else {
      return mid;
    }
  }
  return -1;
}

int search(const int *array, const size_t n, const int k)
{
  int i = 0;
  count = 0;
  for(i = 0; i < n; ++i){
    if(/*count++,*/array[i] == k) return i;
  }
  return -1;
}


void searchtime_test(int algnum,int n, int numtests)
{
  int *num;
  int i,j;
  time_t start;
  num = (int*)malloc(sizeof(int)*n);
  for(i = 0; i < n; ++i){
    num[i] = i;
  }
  start = clock();
  for(j = 0; j < numtests; ++j){
    for(i = 0; i < n; ++i){
      switch(algnum){
        case 0: assert(my_bsearch(num,n,num[i]) == i); break;
        case 1: assert(search(num,n,num[i]) == i); break;
      }
    }
  }
  start = clock() - start;
  printf("%d %d %d : %f\n", algnum, n, numtests, (double)(1000000000*(double)start/1000)/(n*numtests));
  free(num);
}




main()
{
  // int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  // int pos = my_bsearch(a,20,20);
  // int *num;
  // printf("position is: %d, Count is: %d\n", pos, count);
  // pos = search(a,20,20);
  // printf("position is: %d, Count is: %d\n", pos, count);
  searchtime_test(0,1000,1000);
  searchtime_test(0,10000,1000);
  searchtime_test(1,1000,1000);
  searchtime_test(1,10000,1000);
  // searchtime_test(0,100000,1000);
  // searchtime_test(0,1000000,1000);

}