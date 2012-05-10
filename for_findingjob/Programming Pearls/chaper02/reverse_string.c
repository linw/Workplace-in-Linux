/*
 * =====================================================================================
 *
 *       Filename:    reverse_string.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-4 10:47:05
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <stdio.h>
// #include <string.h>
char *reverse(char *a, size_t left, size_t right){
    int i;
    int j;
    char tmp;
    for(i = left,j=0; i < right-j; ++i,j++){
        // tmp = a[i];
        // a[i] = a[right-j];
        // a[right-j] = tmp;
        a[i] ^= a[right-j] ^= a[i] ^= a[right-j];
    }
    return a;
}
char *reverse_string(char *a, int i){
    int n;
    n = strlen(a);
    if(i<=0) return a;

    reverse(a,0,i-1);
    // printf("%s\n", a);
    reverse(a,i,n-1);
    // printf("%s\n", a);
    reverse(a,0,n-1);
    // printf("%s\n", a);
}
main()
{
    char s[] = "abcdefg";
    reverse_string(s,0);
    //reverse(s,0,6);
    printf("%s\n", s);
}
