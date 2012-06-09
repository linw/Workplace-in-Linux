/*
 * =====================================================================================
 *
 *       Filename:    find_max_sum_subarray.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年05月05日 17时21分26秒
 *       Compiler:    gcc
 *       Description: 
 *                problem: find a sub array which has the max sum.
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    return x>y? x:y;
}

// Soluation1: the simplest soluation, but the time O(n^3)
long max_sub_array_1(int *a, int n){
  long max_sum = 1<<31;
  int i;
  int j;
  int k;
  long sum = 0;
  for(i=0;i<n;++i){
    for(j=i;j<n;++j){
      sum = 0;
      for(k=i;k<=j;++k){
        sum += a[k];
      }
      if(sum>max_sum)
	        max_sum = sum;
    }
  }
  return max_sum;  
}


// Soluation2: 优化算法,可以省去一个循环
long max_sub_array_2(int *a, int n){
    long max_sum = 1<<31;
    int i;
    int j;
    int k;
    long sum = 0;
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = i; j < n; ++j){
            sum += a[j];
            if(sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
}

// Soluation3:利用动态规划的思想 
long max_sub_array_3(int *a, int n){
    int *start = malloc(sizeof(int)*n);
    int *all = malloc(sizeof(int)*n);
    int i;
    long _max;
    start[n-1] = a[n-1];
    all[n-1] = a[n-1];
    for(i = n-2; i>=0; --i){
        start[i] = max(a[i],a[i] + start[i+1]);
        all[i] = max(start[i],all[i+1]);
    }
    _max = all[0];
    free(start);
    free(all);
    return _max;
}

// Soluation4: 简化空间复杂度,只需O(1)的空间复杂度就行
long max_sub_array_4(int *a, int n){
    int start;
    int all;
    int i;
    start = a[n-1];
    all = a[n-1];
    for(i = n-2; i>=0; --i){
        start = max(a[i],a[i] + start);
        all = max(start,all);
    }

}

// Soluation5: start 始终加，如果小于零，则清零，all中始终保存最大的和
long max_sub_array_5(int *a, int n){
    int start;
    int all;
    int i;
    start = a[n-1];
    all = a[n-1];
    for(i = n-2; i>=0; --i){
        if(start<0)
            start = 0;
        start += a[i];
        if(start > all)
            all = start;
    }
    return all;
}


main()
{
  int a[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-2};
  printf("%d\n",max_sub_array_1(a,10));
  printf("%d\n",max_sub_array_2(a,10));
  printf("%d\n",max_sub_array_3(a,10));
  printf("%d\n",max_sub_array_4(a,10));
  printf("%d\n",max_sub_array_5(a,10));
}
