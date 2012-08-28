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
void quick_sort1(int *array, const int l, const int r);
void quick_sort2(int *array, const int l, const int r);
void quick_sort3(int *array, const int l, const int r);
long count = 0;
// 用作对比的c中的库函数 qsort()
int compare(const void *a, const void *b)
{
  ++count;
  return ( *(int*)a - *(int*)b);
}

// 交换代码
void swap(int *a, int *b)
{
  if(a == b) 
    return;
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


// 测试时间工具，sort_switch 表示选取的排序算法
void test_running_time(int sort_switch, int n)
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
    insert_sort(array,n);
    break;
  case 1:
    quick_sort1(array,0,n-1);
    break;
  case 2:
    qsort(array,n,sizeof(int), compare);
    break;
  case 3:
    quick_sort2(array,0,n-1);
    break;
  case 4:
    quick_sort3(array,0,n-1);
    break;
  }
  t = clock() - t;
  printf("正向排列的数据测试:结束\n");
  printf("所用总时间为:%ld ms, 平均每个用时:%f ms\n",t,(float)t);


  // 测试逆向排列的数据
  for(i = 0; i < n; ++i)
    array[i] = n - i - 1;
  printf("逆向排列的数据测试:开始\n");
  t = clock();
  switch(sort_switch){
  case 0: 
    insert_sort(array,n);
    break;
  case 1:
    quick_sort1(array,0,n-1);
    break;
  case 2:
    qsort(array,n,sizeof(int), compare);
    break;
  case 3:
    quick_sort2(array,0,n-1);
    break;
  case 4:
    quick_sort3(array,0,n-1);
    break;
  }
  t = clock() - t;
  printf("逆向排列的数据测试:结束\n");
  printf("所用总时间为:%ld ms, 平均每个用时:%f ms\n",t,(float)t);  

  // 测试随机排列的数据
  for(i = 0; i < n; ++i){
    array[i] = rand()%n;
  }
  printf("随机排列的数据测试:开始\n");
  t = clock();
  switch(sort_switch){
  case 0: 
    insert_sort(array,n);
    break;
  case 1:
    quick_sort1(array,0,n-1);
    break;
  case 2:
    qsort(array,n,sizeof(int), compare);
    break;
  case 3:
    quick_sort2(array,0,n-1);
    break;
  case 4:
    quick_sort3(array,0,n-1);
    break;
  }
  t = clock() - t;
  printf("随机排列的数据测试:结束\n");
  printf("所用总时间为:%ld ms, 平均每个用时:%f ms\n",t,(float)t);
}

// 插入排序
void insert_sort(int *array, size_t n)
{
  int i,j;
  int tmp;
  for(i = 1; i < n; ++i){
    tmp = array[i];
    for(j = i; j > 0 && array[j-1] > tmp; --j){
      array[j] = array[j-1];
    }
    array[j] = tmp;
  }
}


// 快速排序
void quick_sort1(int *array, const int l, const int r)
{
  int m;
  int i,j;
  int tmp;
  //  ++count;
  if(l >= r)
    return;
  m = l;
  for(i = l+1; i <= r; ++i){
    if(array[i]<array[l]){
      ++m;
      tmp = array[m];
      array[m] = array[i];
      array[i] = tmp;
    }
  }
  tmp = array[m];
  array[m] = array[l];
  array[l] = tmp;
  quick_sort1(array,l,m-1);
  quick_sort1(array,m+1,r);
}

// 一种优化的快排算法，每次取中间的数
void quick_sort2(int *array, const int l, const int r)
{
  int m;
  int i,j;
  int tmp;
  if(l >= r)
    return;
  //  m = (l+r)/2;
  m = (rand()%(r-l)+l);
  tmp = array[l];
  array[l] = array[m];
  array[m] = tmp;
  m = l;
  for(i = l+1; i <= r; ++i){
    if(array[i]<array[l]){
      ++m;
      tmp = array[m];
      array[m] = array[i];
      array[i] = tmp;
    }
  }
  tmp = array[m];
  array[m] = array[l];
  array[l] = tmp;
  quick_sort2(array,l,m-1);
  quick_sort2(array,m+1,r);
}

// 另一种快排算法，双向划分
void quick_sort3(int *array, const int l, const int r)
{
  int i,j;
  int tmp;
  int tmp1;
  if(l >= r)
    return;
  swap(array+l,array+(l+r)/2);
  tmp = array[l];
  i = l;
  j = r+1;
  do{
    do{
      ++i;
    }while(i <= r && array[i] < tmp);
    do{
      --j;
    }while(array[j] > tmp);
    if(i>j)
      break;
    tmp1 = array[i];
    array[i] = array[j];
    array[j] = tmp1;		
  }while(1);
  swap(array+l,array+j);
  quick_sort3(array,l,j-1);
  quick_sort3(array,j+1,r);
}



// 堆排实现
void heap(int *num, int n)
{
  int i,j;
  int t;
  i = n/2;
  for(i = n/2; i >= 0; --i){
    if(num[i]<num[i*2+1]){
      t = num[i];
      num[i] = num[i*2+1];
      num[i*2+1] = t;
    }
    if(num[i]<num[i*2+2]){
      t = num[i];
      num[i] = num[i*2+2];
      num[i*2+2] = t;
    }
  }
}



main()
{
   /* int a[] = {1,2,3,4,5,6,7,2}; */
   /* int i; */
   /* quick_sort1(a,0,7); */
   /* for(i = 0; i < 8; ++i) */
   /*   printf ("%d ", a[i]); */
  printf("Begin test insert_sort:\n");
  test_running_time(0,100000);
  printf("End test insert_sort!\n\n");

  /* printf("Begin test quick_sort1:\n"); */
  /* //  test_running_time(1,100000); */
  /* printf("End test quick_sort1!\n\n"); */

  printf("Begin test qsort:\n");
  test_running_time(2,1000000);
  printf("End test qsort!\n\n");

  printf("Begin test quick_sort2:\n");
  test_running_time(3,1000000);
  printf("End test quick_sort2!\n\n");

  printf("Begin test quick_sort3:\n");
  test_running_time(4,1000000);
  printf("End test quick_sort3!\n\n");
}
