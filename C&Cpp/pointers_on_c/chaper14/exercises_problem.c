/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-9 14:52:37
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: exercises in chaper14
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
// problem 1: 条件编译
void print_ledger_long(int k)
{
  printf("ledger_long\n");
}
void print_ledger_detailed(int k)
{
  printf("ledger_detailed\n");
}
void print_ledger_default(int k)
{
  printf("ledger_default\n");
}
void fun()
{
#ifdef OPTION_LONG
  print_ledger_long(0);
#endif
#ifdef OPTION_DETAILED
  print_ledger_detailed(0);
#endif
#ifndef OPTION_LONG
#ifndef OPTION_DETAILED
  print_ledger_default(0);
#endif
#endif
}

// problem 2: 编写函数返回计算机类型
// 没什么意思
/* int cpy_type() */
/* { */
/* #ifdef VAX */
/*   return CPU_VAX; */
/* #else */
/*   #ifdef M68000 */
/*   return CPU_68000; */
/*   #else */
/*     #ifdef M68020 */
/*   return CPU_68020; */
/*     #else */
/* #endif */
/* } */




main()
{
  fun();
#ifdef KING
  printf("HHHHHHHHHHHHHHHHHHH\n");
#endif
  fun1();
#ifdef KING
  printf("HHHHHHHHHHHHHHHHHHH\n");
#endif
}
