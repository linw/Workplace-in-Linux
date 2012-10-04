/*
 * =====================================================================================
 *
 *       Filename:    test_mkfifo.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 10:56:24
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int 
main(void)
{
  int fifo_id;
  int n;
  char line[100];
  fifo_id = mkfifo("./fifo1",O_RDWR);
  strcpy(line,"skdjflsdfjls\n");
  n = strlen(line);
  write(fifo_id,line,n);
  n = read(fifo_id,line,100);
  write(STDOUT_FILENO,line,n);
  close(fifo_id);
  return 0;
}
