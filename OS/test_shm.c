/*
 * =====================================================================================
 *
 *       Filename:    test_shm.c
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
#include <sys/shm.h>
#define ARRAY_SIZE 40000
#define MALLOC_SIZE 100000
#define SHM_SIZE 100000
#define SHM_MODE 0600

char array[ARRAY_SIZE];

int
main(void)
{
  int shmid;
  char *ptr, *shmptr;
  printf("array[] from %lx to %lx\n",(unsigned long)&array[0],
	 (unsigned long)&array[ARRAY_SIZE]);
  printf("stack around %lx\n", (unsigned long)&shmid);

  if((ptr = malloc(MALLOC_SIZE)) == NULL){
    printf("malloc error");
    exit(-1);
  }
  printf("malloced from %lx to %lx\n", (unsigned long)ptr,
	 (unsigned long)ptr+MALLOC_SIZE);
  if((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE))<0){
    printf("shmget error");
    exit(-1);
  }
  if((shmptr = shmat(shmid,0,0)) == (void*)-1){
    printf("shmat error");
    exit(-1);
  }
  printf("shared memory attached from %lx to %lx\n",
	 (unsigned long)shmptr, (unsigned long)shmptr+SHM_SIZE);

  if(shmctl(shmid, IPC_RMID,0)<0){
    printf("shmctl error");
    exit(-1);
  }
  if(shmdt(shmptr)>=0){
    exit(0);
  }
  exit(-1);
}
