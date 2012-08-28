/*
 * =====================================================================================
 *
 *       Filename:    alloc.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 12:09:01
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 内存分配器实现
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "alloc.h"
#undef malloc

void *alloc(size_t size)
{
  void *new_mem;
  new_mem = malloc(size);
  if(new_mem == NULL){
    printf("Out of memory!\n");
    exit(1);
  }
  return new_mem;
}


