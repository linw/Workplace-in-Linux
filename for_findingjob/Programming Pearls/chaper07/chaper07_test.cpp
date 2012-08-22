/*
 * =====================================================================================
 *
 *       Filename:    chaper07_test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-21 15:26:09
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 用于计算malloc的消耗,基于一个事实:默认malloc分配空间是在内存上顺序分配的
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MEASURE(T,text) {                    \
  int i,lastp,thisp;			     \
  T* p;                                      \
  printf("%s\t",text);                       \
  printf("%d\t",sizeof(T));                  \
  lastp = 0;                                 \
  for(i = 0; i < 11; ++i) {                  \
    p = new T;                               \
    thisp = (int) p;                         \
    if(lastp != 0)                           \
      printf(" %d",thisp - lastp);           \
    lastp = thisp;                           \
  }                                          \
  printf("\n");                              \
}

typedef struct structint
{
  int i;
}structint;

typedef struct structchar
{
  char i;
}structchar;
typedef struct structlong
{
  long i;
}structlong;

typedef struct structfloat
{
  float i;
}structfloat;

typedef struct structdouble
{
  double i;
}structdouble;

typedef struct struct30
{
  char i[30];
}struct30;

int main()
{
  /* int i; */
  /* int a[100000]; */
  /* for( i = 0; i < 2000000; ++i){ */
  /*   malloc(sizeof(double)); */
  /* } */
  /* scanf("%d",&i); */
  MEASURE(structint,"structint");
  MEASURE(structchar,"structchar");
  MEASURE(structlong,"structlong");
  MEASURE(structfloat,"structfloat");
  MEASURE(structdouble,"structdouble");
  MEASURE(struct30,"struct30");
  return 0;
}
