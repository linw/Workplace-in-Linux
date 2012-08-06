/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-02 17:52:37
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: something in chaper 12
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genknuth(int m, int n)
{
  int i;
  srand((unsigned) time(NULL));
  for(i = 0; i < n; ++i){
    if((rand()% (n-i)) < m) {
      printf("%d\n",i);
      --m;
    }
  }
}


int main()
{
  genknuth(15,100);
  return 0;
}

