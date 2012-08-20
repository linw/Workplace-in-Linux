/*
 * =====================================================================================
 *
 *       Filename:    test_fork.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-14 11:16:49
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int i;
  int k;
  k = 10;
  /* fork(); */
  for(i = 0; i < 2; ++i){
    printf("-");
    k--;
    printf("%d",k);
    //   printf("%d",fork());
  }
  fork();
  //  printf("\n");
}
