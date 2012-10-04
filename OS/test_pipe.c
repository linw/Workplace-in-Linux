/*
 * =====================================================================================
 *
 *       Filename:    test_pipe.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 10:56:24
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  int n;
  int fd[2];
  pid_t pid;
  char line[200];
  if(pipe(fd) < 0){
    printf("pipe error\n");
    return -1;
  }
  if((pid = fork()) < 0){
    printf("fork error\n");
    return -1;
  } else if(pid > 0) {
    close(fd[0]);
    strcpy(line,"hellllllllllllllllllllllllllllsjdfklsjdlfjsldfjsldjflj\n");
    n = strlen(line);
    write(fd[1],line,n);
  } else{
    close(fd[1]);
    n = read(fd[0],line,200);
    write(STDOUT_FILENO, line, n);
  }
  exit(0);
}
