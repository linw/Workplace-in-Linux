/*
 * =====================================================================================
 *
 *       Filename:    testsomething.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-4 20:46:52
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
// #include <iostream>
// using namespace std;
// template<class T1,class T2,class T3>
// T1 sum(T2 a,T3 b){
//     return T1(a+b);
// }
// double d1,d2;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Test(void){
    char*str = (char *) malloc(100);
    strcpy(str,"hello");
    free(str);
    if(str!= NULL){
        strcpy(str,"world");
        printf(str);
    }
}
int f1(void){return 0;}

int add_n(int n) { static int i=100; i+=n; return i;}
main()
{
    // d1 = 10;
    // d2 = 20.5;
    // cout<<sum<int>(d1,d2);
    int a = 4;
    int (*f)(void);
    // int k,*p=&k;
    // int * (m[4]);
    // *p = 10;
    f = f1;
    (++a) = ++a + a;
    printf("%d",a);
    Test();
    printf("%d",sizeof(&f));
    printf("%d\n", add_n(10));
    printf("%d\n", add_n(10));




}
