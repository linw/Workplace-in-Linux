/*
 * =====================================================================================
 *
 *       Filename:    heap_fun.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-28 09:59:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>

int get_parent(int index)
{
  return (index-1)/2;
}

int get_left(int index)
{
  return index*2+1;
}

int get_right(int index)
{
  return index*2+2;
}

// 大顶堆
// 如果未满,则添加元素;如果满了,则替换最后一个元素
int max_siftup(int *array, int n, int size, int data)
{
  int i;
  int tmp;
  int parent;
  int _size;
  if(n<=size){
    i = n-1;
    array[i] = data;
    while(i>0){
      parent = get_parent(i);
      if(array[parent] > array[i]){
	break;
      }
      tmp = array[i];
      array[i] = array[parent];
      array[parent] = tmp;
      i = parent;
    }
    _size = n;
  }
  else {
    i = size;
    array[i] = data;
    while(i>0){
      parent = get_parent(i);
      if(array[parent] > array[i]){
	break;
      }
      tmp = array[i];
      array[i] = array[parent];
      array[parent] = tmp;
      i = parent;
    }
    _size = size+1;
  }
  return _size;
}

int max_siftdown(int *array, int n, int size, int data)
{
  int i;
  int left,right;
  int max_index;
  int tmp;
  i = 0;
  array[0] = data;
  while(i<size){
    left = get_left(i);
    right = get_right(i);
    max_index = i;
    if(array[max_index] < array[left]){
      max_index = left;
    }
    if(array[max_index] < array[right]){
      max_index = right;
    }
    if(max_index == i){
      break;
    }
    tmp = array[i];
    array[i] = array[max_index];
    array[max_index] = tmp;
    i = max_index;
  }
  return size;
}


main(int argv, char* args[])
{
  int heap[10];
  int size = 0;
  int i;
  for(i = 0; i < 6; ++i){
    size = max_siftup(heap,10,size,i);
  }
  size = max_siftdown(heap,10,size,2);
  for(i = 0; i < 10; ++i){
    printf("%d ",heap[i]);
  }
}
