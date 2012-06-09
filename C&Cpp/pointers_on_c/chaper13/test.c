/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-5 20:33:03
 *       Last Edit:   2012-6-6 21:55:01
 *       Compiler:    gcc
 *       Description: something in chaper13
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 翻转
void reverse(char *s)
{
  char *last;
  last = s;
  while(*last)
    ++last;
  --last;
  while(s < last){
    *s ^= *last;
    *last ^= *s;
    *s ^= *last;
    s++;
    last--;
  }
}


// 打印16进制数
void print_to_16(int num)
{
  char a[100];
  int i;
  i = 0;
  a[i++] =  "0123456789ABCDEF"[num%16];
  while(num /= 16){
    a[i++] = "0123456789ABCDEF"[num%16];
  }
  a[i] = 0;
  reverse(a);
  printf("%s\n",a);
}

void print_to_16_1(int num)
{
  if(num/16)
    print_to_16_1(num/16);
  putchar("0123456789ABCDEF"[num%16]);
}

main()
{
  int a[10] = {0};
  int *p = (int *)&a;
  //  *p = (*p)+1;
  //  printf("%d\n",*p);
  //  printf("%d\n",a);
  //  printf("%d\n",&a);
  print_to_16_1(16);
}
