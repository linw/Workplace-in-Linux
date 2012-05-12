/*
 * =====================================================================================
 *
 *       Filename:    find_longest_increase_subarray.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年05月10日 11时53分13秒
 *       Compiler:    gcc
 *       Description:
 *              求数组中的最长递增子序列,并不是子串，是一个增长序列，可以不相邻
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

// soluation1: 利用动态规划的思路,
unsigned int  find_longest_increase_1(const int *a, unsigned int n){
  int i,j;
  unsigned int *tmp = malloc(sizeof(unsigned int)*n);
  unsigned int max = 0;
  for(i = 0; i < n; ++i)
    tmp[i] = 0;
  for(i = 0; i < n; ++i){
    tmp[i] = 1;
    for(j = 0; j < i; ++j){
      if(a[i]>a[j]&&tmp[j]+1>tmp[i])
        tmp[i] = tmp[j] + 1;
    }
  }
  for(i = 0; i < n; ++i)
    if(tmp[i]>max)
      max = tmp[i];
  return max;
}

main()
{
  int a[] = {1,2,3,4,5,6,7,8};
  //  find_longest_increase_1(a,8);
  printf("%d\n",find_longest_increase_1(a,8));
}
