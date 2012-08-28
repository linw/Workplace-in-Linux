/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-9 21:15:00
 *       Last Edit:   2012-6-9 21:15:21
 *       Compiler:    gcc
 *       Description: exercises in chaper 15
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// problem 1: 标准输入到标准输出
void print(FILE *in, FILE *out)
{
  char c;
  while(c = getc(in)){
    putc(c,out);
    //    fflush(stdout);
  }
  //  printf("END");
}

// problem 2&3: 每次读一行，每行不超过80个
void print_line(FILE *in, FILE *out)
{
  char str[81];
  while(fgets(str,81,in))
    fputs(str,out);
}


// problem 4:

main()
{
  //  print(stdin,stdout);
  print_line(stdin,stdout);
}
