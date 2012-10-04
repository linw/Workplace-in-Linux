/*
 * =====================================================================================
 *
 *       Filename:    test_msg.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 10:56:24
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
  long mtype;
  char mtext[512];
}mymesg;
int
main(void)
{
  int msg_id;
  int n;
  mymesg data;
  mymesg data1;
  msg_id = msgget( 1, IPC_CREAT | 0660 );
  data.mtype = 4;
  strcpy(data.mtext,"jsdlfjls\n");
  msgsend(msg_id, data, sizeof(mymesg), IPC_NOWAIT);
  msgrcv(msg_id, (void*)data1.mtext, sizeof(mymesg), 0, IPC_NOWAIT);
  printf("%s\n",data1.mtext);
  return 0;
}
