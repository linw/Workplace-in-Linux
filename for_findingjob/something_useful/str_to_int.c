/*
 * =====================================================================================
 *
 *       Filename:    str_to_int.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-17 21:55:04
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int str_to_int(const char *str)
{
  char tmp;
  int num;
  int flag;
  assert(str);
  flag = 0;
  if(*str == '+'){
    flag = 0;
    ++str;
  }
  else if(*str == '-'){
    flag = 1;
    ++str;
  }
  num = 0;
  while(*str && *str >= '0' && *str <= '9'){
    num = num*10 + *str - '0';
    ++str;
  }
  return flag?-num:num;  
}

main()
{
  printf("%d\n",str_to_int("-154+56"));
  printf("%d\n",atoi("-154+56"));
}
