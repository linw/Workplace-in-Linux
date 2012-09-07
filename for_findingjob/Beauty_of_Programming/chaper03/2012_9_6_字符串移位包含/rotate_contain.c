/*
 * =====================================================================================
 *
 *       Filename:    rotate_contain.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-06 15:49:16
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 字符串循环包含的问题
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

int contain_str1(const char *src, const char *des)
{
  int len;
  char *p;
  int flag;
  len = strlen(src);
  if(len < strlen(des)) return 0;
  len = 2*len+1;
  p = (char*) malloc(sizeof(char)*len);
  strcpy(p,src);
  strcpy(p+len/2,src);
  if(strstr(p,des)){
    flag = 1;
  }
  else {
    flag = 0;
  }
  free(p);
  return flag;
}

int contain_str2(const char *src, const char *des)
{
  int len_s;
  int len_d;
  int i,j;
  len_s = strlen(src);
  len_d = strlen(des);
  if(len_s < len_d) return 0;
  for(i = 0; src[i] != '\0'; ++i){
    for(j = 0; des[j] != '\0'; ++j){
      if(src[(i+j)%len_s] == des[j]){
	continue;
      }
      else break;
    }
    if(j == len_d) return 1;
  }
  return 0;
}


#pragma pack(2) 
struct A 
{ 
    int i; 
    union U 
    { 
        char buff[13]; 
        int i; 
    }u; 
    enum{red, green, blue} color; 
}a; 

main(int argv, char* args[])
{
  if(contain_str1("AABCD","AABCDA")){
    printf("Yes!\n");
  }
  printf("%d\n", sizeof(a));
}
