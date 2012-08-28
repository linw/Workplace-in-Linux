/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-9 15:20:22
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: something in chaper 15
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void main()
{
  int*p;
  FILE* f;
  char c;
  p = NULL;

  perror("what the fuck!\n");
  printf("%d\n",FOPEN_MAX);
  printf("%d\n",FILENAME_MAX);
  f = fopen("data.c","w");
  if(f == NULL){
    perror("data.c");
    exit(EXIT_FAILURE);
  }
  // 成功返回0，失败返回EOF
  /* if(fclose(f)){ */
  /*   perror("data.c"); */
  /* } */
  //  f = fopen("data.c","r");
  while((c = fgetc(f)) !=EOF){
    putchar(c);
  }
  exit(EXIT_FAILURE);
}
