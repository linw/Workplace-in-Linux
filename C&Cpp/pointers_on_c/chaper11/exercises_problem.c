/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 14:13:55
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: exercises problem in chaper11
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// problem 1: 实现calloc函数,内部使用malloc
void *my_calloc( size_t num_elements, size_t element_size)
{
  size_t size;
  char *p;
  int n;
  size = num_elements*element_size;
  p = malloc(size);
  if(p == NULL){
    printf("Out of memory!\n");
    exit(-1);
  }
  while(size)
    p[size--] = 0;
  return p;  
}


// problem 2: 输入一系列数，利用动态分配的数组来保存数据
// 这个题没有难度，不做了

// problem 3: 读取一个字符串，然后复制到动态分配的内存中
// 主要使用了realloc() 函数，这样可以实现不确定大小的动态分配，
// 也可以每次多分配一部分内存，只有到不够用时再分配内存
void get_and_store_str()
{
  char *p;
  char c;
  int i;
  p = NULL;
  i = 0;
  while((c = getchar()) != '\n'){
    p = realloc(p,(i+1)*sizeof(char));
    if(p == NULL){
      printf("Out of memory!\n");
      exit(-1);
    }
    p[i] = c;
    ++i;
  }
  p[i] = 0;
  printf("%s\n",p);
  free(p);
}


// problem 4: 建立一个链表结构
// 很简单，不做了



main()
{
  int *p;
  int i;
  /* p = my_calloc(10,sizeof(int)); */
  p = malloc(10*sizeof(int));
  for(i = 0; i < 10; ++i)
    printf("%d ",p[i]);
  free(p);
  get_and_store_str();
}
