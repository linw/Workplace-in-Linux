/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-9 14:17:42
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: something test in chaper14 
 *
 * =====================================================================================
 */
#
#include <stdio.h>
#include <string.h>
#

main()
{
  printf("%s\n",__FILE__);
  printf("%d\n",__LINE__);
#ifdef __STDC__
  printf("ANSI C\n");
#endif
  printf("%s\n",__DATE__);
#line 10 "king.cc"
  printf("%s\n",__FILE__);
  printf("%d\n",__LINE__);
#error hello
}
