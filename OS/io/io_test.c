/*
 * =====================================================================================
 *
 *       Filename:    io_test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-27 13:04:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <fcntl.h>
main()
{
  int fd = -1; 
  fd = open("./io_test.cpp", O_RDWR | O_CREAT);
  printf("%d\n",fd);
  if(close(fd)){
    printf("close error!\n");
  }
  fd = creat("./king", O_WRONLY | O_CREAT | O_TRUNC);
}
