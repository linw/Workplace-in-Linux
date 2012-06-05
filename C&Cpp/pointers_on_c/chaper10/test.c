/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-3 18:02:52
 *       Last Edit:   2012-6-3 18:00:15
 *       Compiler:    gcc
 *       Description: pointers on c chaper10
 *
 * =====================================================================================
 */
#pragma pack(1)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

typedef struct A{
  int i;
  double j;
  int k;
}A;

typedef struct CHAR {
  unsigned ch :7;
  unsigned font :6;
  unsigned size :20;
}CHAR;

typedef union B{
  float i;
  float j;
}B;

main()
{
  A *p;
  A a = {11,2,3}; 
  int *ip;
  CHAR c;
  B b = {5.5};
  c.ch = 0x7;
  p = &a;
  ip = &(&a)->i;
  printf("%d\n%d\n",p,ip);
  printf("%d\n",offsetof(A,j));
  printf("%d\n",sizeof(CHAR));
  printf("%f\n",b.i);
  printf("%f\n",b.j);
  /* printf("%d\n",&c.ch); */

}
