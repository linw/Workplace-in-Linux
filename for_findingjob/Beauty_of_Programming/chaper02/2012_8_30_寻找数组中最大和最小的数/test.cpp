/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-30 08:18:08
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <iostream>
#include <limits.h>
using namespace std;
typedef struct Result
{
  int max;
  int min;
}Result;


inline void swap(int* a, int* b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

Result find_result1(int *array, int n)
{
  Result r;
  int i,j;
  r.max = INT_MIN;
  r.min = INT_MAX;
  int count;
  count = 0;
  for(i = 0; i+1 < n; i += 2){
    if(count++,array[i]>array[i+1]){
      swap(array+i,array+i+1);
    }
  }
  for(i = 0; i < n; i += 2){
    if(count++,r.min>array[i]){
      r.min = array[i];
    }
  }
  for(i = 1; i < n; i += 2){
    if(count++,r.max<array[i]){
      r.max = array[i];
    }
  }
  cout<<"compare times:"<<count<<endl;
  return r;
}

Result find_result2(int *array, int n)
{
  Result r;
  int i;
  int count;
  int max,min;
  r.min = INT_MAX;
  r.max = INT_MIN;
  count = 0;
  for(i = 0; i+1 < n; i += 2){
    if(count++,array[i]>array[i+1]){
      min = array[i+1];
      max = array[i];
    }
    else {
      min = array[i];
      max = array[i+1];
    }
    if(count++,max>r.max){
      r.max = max;
    }
    if(count++,min<r.min){
      r.min = min;
    }
  }
  if(count++,i == n-1){
    if(count++,r.min>array[i]){
      r.min = array[i];
    }
    else if(count++,r.max<array[i]){
      r.max = array[i];
    }
  }
  cout<<"compare times:"<<count<<endl;
  return r;
}

int find_second_max(int *array, int n)
{
  int max;
  int sec_max;
  int i;
  max = INT_MIN;
  sec_max = INT_MIN;
  for(i = 0; i < n; ++i){
    if(max<array[i]){
      sec_max = max;
      max = array[i];
    }
  }
  return sec_max;
}


int main(int argv, char* args[])
{
  int a[] = {5,6,8,3,7,9};
  Result r;
  r= find_result2(a,6);
  cout<<r.max<<" "<<r.min<<endl;
  cout<<find_second_max(a,6)<<endl;
  int *p;
  int (*q)[10];
  q = new int[10][10];
  p = (int*)q;
  int i;
  for(i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      q[i][j] = i*10+j;
    }
  }
  for(i = 0; i < 100; ++i){
    cout<<*(p+i)<<endl;
  }
  
  return 0;
}
