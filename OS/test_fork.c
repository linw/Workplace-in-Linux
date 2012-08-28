/*
 * =====================================================================================
 *
 *       Filename:    test_fork.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-22 10:32:33
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>



//   data[100];
//   int thread_function(void* a)
//   {
//     int i;
//     for(i = 0; i < 100; ++i){
//       printf("%d ",data[i]);
//     }
//     return 0;
//   }
//   
//   
//   void foo()
//   {
//     clone(thread_function,data,CLONE_VM,0);
//   }
int data[100];
main(int argv, char* args[])
{
  int pid;
  int data[100];
  pid = fork();
  if(pid < 0){
    printf("Error!\n");
  }
  else if( pid == 0){
    printf("child process!\n");
  }
  else {
    printf("parent process, child process pid is: %d\n",pid);
  }
}
