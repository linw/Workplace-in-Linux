/*
 * =====================================================================================
 *
 *       Filename:    heap_test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-26 16:00:45
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
void max_heap(int *array, int n, int index)
{
  /* int left,right; */
  /* int max_index; */
  /* int tmp; */
  /* left = index*2+1; */
  /* right = index*2+2; */
  /* max_index = index; */
  /* if(left < n && array[index]<array[left]){ */
  /*   max_index = left; */
  /* } */
  /* if(right < n && array[max_index]<array[right]){ */
  /*   max_index = right; */
  /* } */
  /* if(max_index == index){ */
  /*   return; */
  /* } */
  /* tmp = array[index]; */
  /* array[index] = array[max_index]; */
  /* array[max_index] = tmp; */
  /* max_heap(array,n,max_index); */// 使用递归的方法，空间复杂度会变大
  int left,right;
  int max_index;
  int tmp;
  left = index*2+1;
  right = index*2+2;
  max_index = index;
  while(left<n || right<n){
    max_index = index;
    if(left < n && array[max_index]<array[left]){
      max_index = left;      
    }
    if(right < n && array[max_index]<array[right]){
      max_index = right;
    }
    if(max_index == index){
      break;
    }
    tmp = array[index];
    array[index] = array[max_index];
    array[max_index] = tmp;
    index = max_index;
    left = index*2+1;
    right = index*2+2;
  }
}

void max_build_heap(int *array, int n)
{
  int i;
  for(i = n/2; i >= 0; --i){
    max_heap(array,n,i);
  }
}

void max_heap_sort(int *array, int n)
{
  int i;
  int tmp;
  max_build_heap(array,n);
  for(i = n; i >= 1; --i){
    max_heap(array,i,0);
    tmp = array[0];
    array[0] = array[i-1];
    array[i-1] = tmp;
  }
}

void min_heap(int *array, int n, int index)
{
  /* int left,right; */
  /* int min_index; */
  /* int tmp; */
  /* left = index*2+1; */
  /* right = index*2+2; */
  /* min_index = index; */
  /* if(left < n && array[min_index]>array[left]){ */
  /*   min_index = left; */
  /* } */
  /* if(right < n && array[min_index]>array[right]){ */
  /*   min_index = right; */
  /* } */
  /* if(min_index == index){ */
  /*   return; */
  /* } */
  /* tmp = array[index]; */
  /* array[index] = array[min_index]; */
  /* array[min_index] = tmp; */
  /* min_heap(array,n,min_index); */// 递归实现，空间复杂度加大
  int left,right;
  int min_index;
  int tmp;
  left = index*2+1;
  right = index*2+2;
  while(left<n || right<n){
    min_index = index;
    if(left < n && array[min_index]>array[left]){
      min_index = left;      
    }
    if(right < n && array[min_index]>array[right]){
      min_index = right;
    }
    if(min_index == index){
      break;
    }
    tmp = array[index];
    array[index] = array[min_index];
    array[min_index] = tmp;
    index = min_index;
    left = index*2+1;
    right = index*2+2;
  }
}

void min_build_heap(int *array, int n)
{
  int i;
  for(i = n/2; i >=0; --i){
    min_heap(array,n,i);
  }
}

void min_heap_sort(int *array, int n)
{
  /* int i; */
  /* int *a; */
  /* int tmp; */
  /* a = (int*) malloc(sizeof(int)*n); */
  /* for(i = 0; i < n; ++i){ */
  /*   a[i] = array[i]; */
  /* } */
  /* min_build_heap(a,n); */
  /* for(i = 0; i < n; ++i){ */
  /*   array[i] = a[0]; */
  /*   a[0] = a[n-i-1]; */
  /*   min_heap(a,n-i-1,0); */
  /* } */
  /* free(a); */
  int i,j;
  int tmp;
  min_build_heap(array,n);
  for(i = n; i >= 1; --i){
    min_heap(array,i,0);
    tmp = array[0];
    array[0] = array[i-1];
    array[i-1] = tmp;
  }
  i = 0;
  j = n-1;
  while(i<j){
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    i++;
    j--;
  }
}



main(int argv, char* args[])
{
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  int i;
  min_heap_sort(a,10);
  //  min_build_heap(a,10);
  // min_heap(a,10,0);
  for(i = 0; i < 10; ++i){
    printf("%d ",a[i]);
  }
}
