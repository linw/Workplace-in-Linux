/*
 * =====================================================================================
 *
 *       Filename:    sort_using_bitmap.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-24 21:18:54
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 1000000
int p[1+N/BITSPERWORD];



void set(int i){
    // 每个int型变量中可以存放32个数，所以
    p[i >> SHIFT] |= (1<<(i & MASK));
}

void clr(int i){
    p[i >> SHIFT] &= ~(1<<(i & MASK));
}

int test(int i){
    return p[i >> SHIFT] & (1<<(i & MASK));
}

main(){
    int i = 0;
    time_t pre;
    time_t after;
    FILE* fp;
    char s[10];
    int a[100000];
    fp = fopen("out1.dat","w");
    for(i = 0; i < 1+N/BITSPERWORD; ++i)
        p[i] = '\0';    
    for(i = 0; i < 100000; ++i){
        a[i] = rand()%10000;
        fputc(a[i],fp);
    }
    fclose(fp);
    fp = fopen("out2.dat","w");
    printf("\n");
    for(i = 0; i < 100000; ++i)
        set(a[i]);
    for(i = 0; i < 100000; ++i)
        if(test(i)){
            fputc(a[i],fp);
        }
    fclose(fp);
}
