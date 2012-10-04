/*
 * =====================================================================================
 *
 *       Filename:    replace_space.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-29 16:01:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 替换字符串中的空格
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// src 源字符串(足够长); rstred 需要被替换的字符串; rstr 要被替换成的字符串
char * replace_str(char* const src, const char rchar, const char* rstr) 
{  
  assert(src&&rstr);
  int len_src = strlen(src);
  int len_rstr = strlen(rstr);
  char *p1;
  char *p2;
  int rstred_times = 0;
  int i;
  p1 = src;
  while(*p1){
    if(*(p1++) == rchar){
      ++rstred_times;
    }
  }
  p1 = src + len_src;
  p2 = p1 + rstred_times*(len_rstr - 1);
  while(p1 != p2){
    if(*p1 == rchar){
      --p1;
      for(i = len_rstr-1; i >= 0; --i){
	*(p2--) = rstr[i];
      }
    }
    else {
      *(p2--) = *(p1--);
    }
  }
  return src;
}

int main(void)
{
  char src[100] = "hello the world.";
  replace_str(NULL, 'a', "%20");
  printf("%s\n",src);
  return 0;
}
