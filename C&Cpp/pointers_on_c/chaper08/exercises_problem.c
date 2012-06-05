/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-24 22:18:55
 *       Last Edit:   2012-5-24 22:19:00
 *       Compiler:    gcc
 *       Description: pointers on c chaper8 exercises
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <stdarg.h>
// problem 2: 美国政府计算个税
static float income_limit[] = {0,23350,56550,117950,256500,DBL_MAX};
static float base_tax[] = {0,3502.50,12798.50,31832.50,81710.50};
static float percentage[] = {.15, .28, .31, .36, .396};
float single_tax(float income)
{
  int i;
  for(i = 0; i < sizeof(income_limit)/sizeof(float); ++i){
    if(income<income_limit[i])
      break;
  }
  printf("%d\n",i);
  return base_tax[i-1] + (income-income_limit[i-1])*percentage[i-1];
}

int test(int a[])
{
  return sizeof(a);
}

// problem 3: 判断单位矩阵
int identity_matrix(int matrix[][10],int n)
{
  int i,j;
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j){
      if(i!=j&&matrix[i][j]!=0) return 0;
      else if(i == j && matrix[i][j] != 1) return 0;
    }
  return 1;
}

// problem 4: 扩展problem3
int identity_matrix_extend(int *matrix, int n)
{
  int i,j;
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j){
      if(i !=j && matrix[i*10+j] != 0)
	return 0;
      else if(i == j && matrix[i*10+j] !=1)
	return 0;
    }
  return 1;
}

// problem 5: 实现矩阵相乘
// m1 is m1[x][y], m2 is m2[y][z], r is r[x][z]
void matrix_multiply( int *m1, int *m2, int *r,
		      int x, int y, int z)
{
  int i,j,k;
  for(i = 0; i < x; ++i){
    for(j = 0; j < z; ++j){
      for(k = 0; k < y; ++k){
	r[i*z+j] += m1[i*y+k]*m2[k*z+j];
      }
    }
  }
}


// problem 6: 计算array offset 函数，按行为主序存储
int array_offset( int arrayinfo[], ...)
{
  va_list args;
  int offset;
  int n;
  int begin;
  int end;
  int i,j;
  n = arrayinfo[0];
  va_start(args,arrayinfo);
  offset = begin = end =0;
  for(i = 1; i < 2*n;i+=2){
    begin = arrayinfo[i]; // array area begin num
    end = arrayinfo[i+1]; // array area end num
    j = va_arg(args,int); // get arg
    if(j>end||j<begin) return -1; // out of area
    offset = offset*(end - begin+1) + j-begin; // comput offset 
  }
  va_end(args);
  return offset;
}

// problem 7: 计算array offset 函数，按列为主序存储
int array_offset2(int arrayinfo[], ...)
{
  va_list args;
  int offset;
  int n;
  int begin;
  int end;
  int i,j;
  int *p_args;
  offset = begin = end = i = j = 0;
  n = arrayinfo[0];
  p_args = (int*) malloc(n*sizeof(int));
  va_start(args,arrayinfo);
  for(i = 0; i < n; ++i)
    p_args[i] = va_arg(args,int);
  va_end(args);
  //  printf("AAAAAAAA\n");
  //  for(i = 0; i <n ;++i)
  //   printf("%d ",p_args[i]);
  for(i = 2*n; i>1; i -= 2){ //  注意arrayinfo的长度为2n+1,arrayinfo[0]保存信息
    begin = arrayinfo[i-1];
    end = arrayinfo[i];
    j = p_args[(i-1)/2];
    //    printf("\nbegin:%d, end:%d\n j:%d\n",begin,end,j);
    if(j>end||j<begin) return -1;
    offset = offset*(end-begin+1)+j-begin;
  }
  free(p_args);
  return offset;
}


// problem 8: eight queen
int can_eat(int x1,int y1,int x2, int y2)
{
  if(x1 == x2||
     y1 == y2||
     x2-x1 == y2-y1)
    return 1;
  return 0;
}
void eight_queen(int queen[][8], int n)
{
  int i,j;
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      queen[i][j] = 0;
  
}

main()
{
  int a[] = {1,2,3,4,5,6,7,8};
  int m1[3][2] = {
    {2,-6},
    {3,5},
    {1,-1}
  };
  int m2[2][4] = {
    {4,-2,-4,-5},
    {-7,-3,6,7}
  };
  int r[3][4] = {0};
  int i,j;
  int arrayinfo[] = {3,4,6,1,5,-3,3};
  printf("%f\n",single_tax(256510));
  printf("%d\n",test(a));
  matrix_multiply(m1,m2,r,3,2,4);
  for(i = 0; i<3;++i)
    for(j = 0; j < 4; ++j)
      printf("%d ",r[i][j]);
  i = array_offset2(arrayinfo,6,5,3);
  printf("%d\n",i);
}
