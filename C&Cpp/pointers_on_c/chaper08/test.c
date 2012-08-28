/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-3 10:56:25
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <stdio.h>
void fun(int **mat, size_t m, size_t n){
    int i,j;
    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j)
            printf("%d ",*(mat+n*i+j));
        printf("\n");
    }
}
void swap(int *a, int *b){
    if(a==b) return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
main()
{
    int a[2][2] = {{1,2},{3,4}};
    int **p = a;
    int arr[] = {123,7654};
    int i,j;
    int first = ~(1<<31);
    int second = 1;
    // printf("a+b = %d\n",first+second);
    printf("a,b before is: %d, %d\n",first,second);
    swap(&first,&second);
    printf("a,b now is: %d, %d\n",first,second);
    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j)
            printf("%d ",*(p+2*i+j));
        printf("\n");
    }
    
    fun(a,2,2);
    arr[0] ^= arr[1] ^= arr[0] ^= arr[1];
    printf("%d,%d\n", arr[0],arr[1]);

}

