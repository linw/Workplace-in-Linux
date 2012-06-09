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
  FILE* ff;
  char c;
  char buffer[100];
  unsigned int ibuffer[100];
  p = NULL;

  perror("what the fuck!\n");
  printf("%d\n",FOPEN_MAX);
  printf("%d\n",FILENAME_MAX);
  f = fopen("data.c","r");
  if(f == NULL){
    perror("data.c");
    exit(EXIT_FAILURE);
  }
  // 成功返回0，失败返回EOF
  /* if(fclose(f)){ */
  /*   perror("data.c"); */
  /* } */
  //  f = fopen("data.c","r");
  while((fgets(buffer,100,f))!=NULL){
    puts(buffer);
  }
  putchar('abc');
  putc('k',f);
  sscanf("12 12","%d %d",&c,&c);
  printf("%d\n",c);
  printf("%5s\n","bcdea");
  if(fclose(f)){
    perror("data.c");
    exit(EXIT_FAILURE);
  }
  ff = fopen("data.dat","wb");
  if(ff == NULL){
    perror("data.dat");
    exit(EXIT_FAILURE);
  }
  ibuffer[0] = 4023817;
  ibuffer[1] = 2;
  ibuffer[2] = 1;
  ibuffer[3] = 1<<31;
  fwrite(ibuffer,sizeof(int),4,ff);
  fflush(ff);
  strcpy(buffer,"hello world\n");
  fputs(buffer, stdout);
  printf("length:%d\n",ftell(stdin));
  printf("%d\n",BUFSIZ);
  if(fclose(ff)){
    perror("data.dat");
    exit(EXIT_FAILURE);
  }
  printf("%s\n",tmpnam(NULL));
  remove("./data.dat");
}
