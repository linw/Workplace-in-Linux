/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-14 21:52:37
 *       Last Edit:   2012-5-14 21:53:00
 *       Compiler:    gcc
 *       Description: pointers on c chaper4 exercises
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
// 1.求近似平方根
double my_sqrt(double d){
  double tmp = 1;
  double tmp1;
  tmp1 = -1;
  while(tmp1-tmp>0.00001||tmp1-tmp<-0.00001){
    tmp1 = tmp;
    tmp = (tmp +d/tmp)/2;
  }
  return tmp;
}
// 2.寻找质数
void print_prime_number(unsigned int n){
  int i,j;
  int flag;
  for(i=1;i<=n;++i){
    flag = 1;
    for(j=2;j<=i/2;++j){
      if(i%j == 0) {flag = 0;break;}
    }
    if(flag)printf("%d ",i);
  }
}

// 3.判断属于什么三角形
int which_kind_triangle(int a,int b,int c){
  if(a==b&&a==c) return 0;
  if(a==b||a==c||b==c) return 1;
  return 2;
}
void print_which(int a, int b, int c){
  switch(which_kind_triangle(a,b,c)){
  case 0:
    printf("等边三角形");break;
  case 1:
    printf("等腰三角形");break;
  case 2:
    printf("不等边三角形");break;
  default:
    printf("输入数据有错误");break;
  }
}

// 4. 编写copy_n函数，原型如下
// void copy_n(char dst[], char src[], int n);
void copy_n(char dst[], char src[], int n){
  int i;
  //  unsigned int d_len;
  unsigned int s_len;
  //  d_len = sizeof(dst)/sizeof(char);
  s_len = sizeof(src)/sizeof(char);
  for(i = 0; i < n && i < s_len; ++i){
    dst[i] = src[i];
  }
  for(;i<=n;++i){
    dst[i] = '\0';
  }
}


main()
{
  int a,b,c;
  printf("%f\n",my_sqrt(10));
  print_prime_number(100);
  a = b = c = 10;
  print_which(a,b,c);
}
