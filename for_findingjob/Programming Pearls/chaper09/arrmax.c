/*
 * =====================================================================================
 *
 *       Filename:    arrmax.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-25 10:37:52
 *       Last Edit:   2012-7-25 11:21:04
 *       Compiler:    gcc
 *       Description: 寻找最大子向量
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>


#define max(a,b) ((a) > (b) ? (a) : (b))

/* float max(float a, float b) */
/* { */
/*   return a>b?a:b; */
/* } */

int arrmax(const int *num, int n)
{
  if(1 == n){
    return num[0];
  }
  else {
    return max(num[n-1],arrmax(num,n-1));
  }
}

int arrmax1(int *num, int n)
{
  int max;
  int i;
  i = 0;
  while(i<n-1){
    max = num[i];
    num[n-1] = max;
    ++i;
    while(max>num[i]){
      ++i;
    }
  }
  return max;
}


main()
{
  int num[31] = {30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  time_t t;
  t = clock();
  //  arrmax(num,30);
  printf("%d\n",arrmax1(num,31));
  t = clock() - t;
  printf("%ld\n", t);
}
