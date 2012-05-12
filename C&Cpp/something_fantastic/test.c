/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-1 19:20:48
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
// #include "stdio.h"
// typedef int* int_ptr;
#include <stdio.h>
enum A{king=1,kings=2};
int main() {
    enum A aa;
    aa = king;
    printf("%d\n",aa);
    FILE *fp = NULL;
    fp = fopen("data.dat","wb");
    int a = 1 << 30;
    int b = -a;
//    fwrite(&a,sizeof(int),1,fp);
    fwrite(&b,sizeof(int),1,fp);
    fclose(fp);
    printf("%d\n", a);
    printf("%d\n", b);
    if(a > b)
        printf("a > b.\n");
    if(a - b > 0)
        printf("a - b > 0.\n");
    printf("a - b = %d.\n", a - b);


    return 0;
}
// main()
// {
//     // const int i = 10;
//     // const int const const * const const a = &i;
//     // int * const b = &i;
//     // const int_ptr c = &i;
//     // // a++;
//     // *c = 10;
//     // *b = 20;
//     // *c = 10;
//     // const int* &q = &i;
//     // printf("%d\n", i);
//     // int i;
//     // static int k;
//     // int i=1;
//     // static int j;
//     // static int k=1;
//     // static int m=2;
//     // printf("hello\n");
//     // main();


// }
