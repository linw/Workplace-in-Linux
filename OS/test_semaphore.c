/*
 * =====================================================================================
 *
 *       Filename:    test_semaphore.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 10:56:24
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/sem.h>
int semget(key_t key, int nsems, int flag);
int semctl(int semid, int semnum, int cmd);
int semop(int semid, struct sembuf semoparray[], size_t nops);

