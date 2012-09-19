/*
 * =====================================================================================
 *
 *       Filename:    first_socket.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-15 10:51:32
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <sys/socket.h>
#include <netdb.h>
#define MAXSLEEP 128
int
connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
  int nsec;
  for(nsec = 1; nsec <= MAXSLEEP; nsec <<= 1){
    if(connect(sockfd, addr, alen) == 0){
      return 0;
    }
    if(nsec <= MAXSLEEP/2){
      sleep(nsec);
    }
  }
  return -1;
}
main(int argv, char* args[])
{
  int sockfd = -1;
  struct sockaddr my_addr;
  int err_no;
  struct sockaddr_in *addr;
  addr = (struct sockaddr_in*)&my_addr;
  addr->sin_port = 0;
  addr->sin_addr.s_addr = INADDR_ANY;
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  err_no = bind(sockfd, (struct sockaddr*)addr, sizeof(struct sockaddr));
  //  err_no = connect(sockfd, (struct sockaddr*)addr, sizeof(struct sockaddr));
  printf("%d\n",err_no);
  //err_no = connect_retry(sockfd, (struct sockaddr*)addr, sizeof(struct sockaddr));
  
}
