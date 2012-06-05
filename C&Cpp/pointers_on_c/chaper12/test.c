/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 14:51:22
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: something in chaper12
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// List
typedef struct NODE{
  NODE *next;
  int ele;
}NODE;

// DList
typedef struct DNODE{
  DNODE *fwd;
  DNODE *bwd;
  int value;
}DNODE;

main()
{
  const int i = 10;
  const int *p;
  p = (int*)&i;
  /* printf("%d\n",i); */
  /* printf("%d\n",*p); */
  /* int j; */
  /* char *p = "Hello world!"; */
  /* j = *(&i); */
  /* p[1] = 'a'; */
  /* printf("%s\n",p); */
  /* /\* printf("%d\n",*(p-2)); *\/ */
  printf("%d\n",p);
  printf("%d\n",&i);
  //  scanf("%d",&i);
  //  printf("%d\n",i);
}
