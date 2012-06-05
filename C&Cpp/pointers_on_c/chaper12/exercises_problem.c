/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 22:26:14
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: exercises in chaper12
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// list
typedef struct NODE{
  NODE *next;
  int elem;
}NODE;

// dlist
typedef struct DNODE{
  DNODE *fwd;
  DNODE *bwd;
  int elem;
}DNODE;



// problem 1: 统计一个单链表中节点的个数
// 可用于遍历单链表
int traverse_count_list(NODE const *root)
{
  int count;
  count = 0;
  while(root){
    root = root->next;
    ++count;
  }
  return count;
}





main()
{
  int i;
  NODE *p;
  NODE *root;
  root = p = NULL:
  for(i = 0; i < 10; ++i){
    p = NULL;
    p = (NODE *) malloc(sizeof(NODE));
    if(p == NULL) {
      printf("Out of memory!\n");
      exit(-1);
    }
    p->elem = i;
    p->next = NULL;
    if(root == NULL)
      root = p;
    else 
}
