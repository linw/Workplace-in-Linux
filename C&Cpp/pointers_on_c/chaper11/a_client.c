/*
 * =====================================================================================
 *
 *       Filename:    a_client.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 13:12:11
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 内存分配器实现
 *
 * =====================================================================================
 */
#include "alloc.h"
main()
{
  int *new_memory;
  int i;
  new_memory = MALLOC(25,int);
  for(i = 0; i < 25; ++i)
    new_memory[i] = i;
  for(i = 0; i < 25; ++i)
    printf("%d ",new_memory[i]);
  free(new_memory);
  //  printf("\n");
  for(i = 0; i < 25; ++i)
    printf("%d ",new_memory[i]);
  
}
