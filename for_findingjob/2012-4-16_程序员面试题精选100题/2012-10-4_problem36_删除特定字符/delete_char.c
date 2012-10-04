/*
 * =====================================================================================
 *
 *       Filename:    delete_char.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 16:12:44
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* delete_char(char *str, char c)
{
  assert(str);
  char *pslow, *pfast;
  pslow = pfast = str;
  while(*pfast){
    if(*pfast == c){
      ++pfast;
      continue;
    }
    *pslow++ = *pfast++;
  }
  *pslow = '\0';
  return str;
}


int
main(void)
{
  char a[] = "hello the woeeeerleeeed!";
  char *p;
  p = delete_char(a,'e');
  printf("%s\n",p);
  return 0;
}
