/*
 * =====================================================================================
 *
 *       Filename:    print_all_str.c
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

void print_all_str(char* str, char* begin)
{
  assert(str&&begin);
  char tmp;
  char *p;
  int len = strlen(str);
  int b_len = strlen(begin);
  if(*begin == '\0'){
    printf("%s\n",str);
    return;
  }
  for(p = begin; *p != '\0'; ++p){
    tmp = *p;
    *p = *begin;
    *begin = tmp;
    print_all_str(str,begin+1);
    tmp = *p;
    *p = *begin;
    *begin = tmp;
  }
}

/* void print_all_str1(char* str, char* begin) */
/* { */
/*   assert(str); */
/*   char tmp; */
/*   char *p; */
/*   if(*begin == '0'){ */
/*     //    printf("%s\n",str); */
/*     return; */
/*   } */
/*   tmp = *begin; */
/*   for(p = begin; *p != '\0'; ++p){ */
/*     *begin = *p; */
/*     *p = tmp; */
/*     printf("%s\n", str); */
/*     *p = *begin; */
/*     *begin = tmp; */
/*   } */
/*   print_all_str1(str,begin+1); */
/* } */

int
main(void)
{
  char buffer[] = "abc";
  //  print_all_str(buffer,buffer);
  print_all_str(buffer,buffer);
  exit(0);
}
