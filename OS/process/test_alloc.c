/*
 * =====================================================================================
 *
 *       Filename:    test_alloc.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-27 13:04:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main()
{
  int *p;
  int i;
  p = malloc(sizeof(int)*10);
  free(p);
  /* for(i = 0; i < 2; ++i){ */
  /*   fork(); */
  /*   printf("-"); */
  /* } */
  for(i = 0; i < 10; ++i){
    printf("Hello\n");
    printf("%d\n",sleep(2));
  }
}
