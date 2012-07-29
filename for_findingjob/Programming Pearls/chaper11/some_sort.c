/*
 * =====================================================================================
 *
 *       Filename:    some_sort.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-28 23:03:45
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 一些排序问题
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void insert_sort(int *array, size_t n);

// 测试时间工具，sort_switch 表示选取的排序算法
void test_running_time(int sort_switch, int n, int numtest)
{
  int *array = (int*)malloc(sizeof(int)*n);
  int i;
  time_t t;
  // 首先，测试正向排列的数据
  for(i = 0; i < n; ++i)
    array[i] = i;
  printf("正向排列的数据测试:开始\n");
  t = clock();
  switch(sort_switch){
    case 0: 
      for(i = 0; i < numtest; ++i)
        insert_sort(array,n);
      break;
  }
  t = clock() - t;
  printf("正向排列的数据测试:结束\n");
  printf("所用总时间为:%lu ms, 平均每个用时:%f ms\n",t,(float)t/numtest);


  // 测试逆向排列的数据
  for(i = 0; i < n; ++i)
    array[i] = n - i - 1;
  printf("逆向排列的数据测试:开始\n");
  t = clock();
  switch(sort_switch){
    case 0: 
      for(i = 0; i < numtest; ++i)
        insert_sort(array,n);
      break;
  }
  t = clock() - t;
  printf("逆向排列的数据测试:结束\n");
  printf("所用总时间为:%lu ms, 平均每个用时:%f ms\n",t,(float)t/numtest);  


  // 测试随机排列的数据
  for(i = 0; i < n; ++i){
    array[i] = rand()%n;
  }
  printf("随机排列的数据测试:开始\n");
  t = clock();
  switch(sort_switch){
    case 0: 
      for(i = 0; i < numtest; ++i)
        insert_sort(array,n);
      break;
  }
  t = clock() - t;
  printf("正向排列的数据测试:结束\n");
  printf("所用总时间为:%lu ms, 平均每个用时:%f ms\n",t,(float)t/numtest);
}

// 插入排序
void insert_sort(int *array, size_t n)
{
  int i,j,t;
  for(i = 1; i < n; ++i){
    t = array[i];
    for(j = i; j > 0 && array[j-1] > t; --j){
      array[j] = array[j-1];
    }
    array[j] = t;
  }
}

// 快速排序
void quick_sort(int *array, size_t n)
{

}

main()
{
  test_running_time(0,1000000,1);
}