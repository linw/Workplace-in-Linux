/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-3 22:30:38
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: pointers on c chaper11 
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define malloc
#define MALLOC(num,type) (type *) alloc( (num) *sizeof(type))
extern void *alloc(size_t size);

main()
{
  int *p;
  int k[100000];
  int i;
  p = NULL;
  p = (int*) malloc(sizeof(int)*100000*1000000);
  if(p == NULL) printf("can't init memory!\n");
  scanf("%d",&i);
  free(p);
  p = NULL;
  /* p = (int*) malloc(sizeof(int)*10); */
  p = (int*) calloc(10,sizeof(int));
  free(p);
}
