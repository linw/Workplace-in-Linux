/*
 * =====================================================================================
 *
 *       Filename:    problem6.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-24 14:33:27
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>

int my_isdigit(const char c)
{
  if(c>='0'&&c<='9'){
    return 1;
  }
  return 0;
}

int my_isupper(const char c)
{
  if(c>='A'&&c<='Z'){
    return 1;
  }
  return 0;
}

int my_islower(const char c)
{
  if(c>='a' && c<='z'){
    return 1;
  }
  return 0;
}
