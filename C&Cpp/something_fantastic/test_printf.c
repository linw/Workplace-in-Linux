/*
 * =====================================================================================
 *
 *       Filename:    test_printf.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-22 23:06:09
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>

main(int argv, char* args[])
{
  int i;
  i = 0;
  printf("%d,%d,%d",++i,++i,++i);
}
