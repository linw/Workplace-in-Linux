/*
 * =====================================================================================
 *
 *       Filename:    longest_str.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-08 10:38:38
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 最长回文的求解
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int longest_str(const char* str)
{
  assert(str);
  int len;
  char* tmp_str;
  int i,j,k;
  char* p1;
  char* p2;
  int longest_len;
  int tmp_len;
  len = strlen(str);
  tmp_str = (char*) malloc(sizeof(char)*len*2);
  p1 = str;
  p2 = tmp_str;
  while(*p1){
    *p2++ = *p1;
    if(*(p1+1)){
      *p2++ = '#';
    }
    ++p1;
  }
  *p2 = '\0';
  longest_len = 1;
  for(i = 1; i < len*2-1; ++i){
    tmp_len = 1;
    for(j = i-1,k = i+1; j>=0&&k<len*2-1;--j,++k){
      if(tmp_str[j] == tmp_str[k]){
	++tmp_len;
	++tmp_len;
	continue;
      }
      break;
    }
    if(longest_len<tmp_len){
      longest_len = tmp_len;
    }    
  }
  free(tmp_str);
  return longest_len - longest_len/2;
}

int
main(void)
{
  printf("%d\n",longest_str("aaaaaaa"));
  return 0;
}
