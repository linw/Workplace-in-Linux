/*
 * =====================================================================================
 *
 *       Filename:    find_max_subarray.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年05月10日 10时19分45秒
 *       Compiler:    gcc
 *       Description: 
 *                子数组之和的最大值，扩展到二维
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
// share function: return max
int max(int a, int b){
    return a>b? a:b;
}
long sum_array(int *a,unsigned int n, unsigned int m,unsigned int min_i,unsigned int max_i,unsigned int min_j,unsigned int max_j){
    long sum;
    int i,j;
    sum = 0;
    for(i=min_i;i<=max_i;++i)
        for(j=min_j;j<=max_j;++j)
            sum += a[i*m+j];
    return sum;
}
// solution1: search every rectangle, most simplest.
long find_max_subarray_sum(int *a, unsigned int n, unsigned int m){
    unsigned int min_i,min_j,max_i,max_j;
    unsigned int i,j,k;
    long max_sum = 1<<31;
    for(min_i = 0; min_i < n; ++min_i){
        for(max_i = min_i; max_i < n; ++max_i){
            for(min_j = 0; min_j < n; ++min_j){
                for(max_j = min_j; max_j < n; ++max_j){
                    max_sum = max(max_sum,sum_array(a,n,m,min_i,max_i,min_j,max_j));     
                }
            }
        }
    }
    return max_sum;
}
// solution2: 
main()
{
    int a[9] = {1,2,3,4,5,6,7,8,9};
//    printf("%d",sum_array(a,3,3,0,1,0,2));
    printf("%d",find_max_subarray_sum(a,3,3));
}
