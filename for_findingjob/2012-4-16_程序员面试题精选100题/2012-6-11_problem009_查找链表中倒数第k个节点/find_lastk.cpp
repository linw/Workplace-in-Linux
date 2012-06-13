/*
 * =====================================================================================
 *
 *       Filename:    find_lastk.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-11 14:02:15
 *       Last Edit:
 *       Compiler:    gcc
 *       Description:
 *              题目：查找链表中倒数第 k 个结点
 *              理解：维持两个指针，并使这两个指针之间相差为k
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct LISTNODE{
  struct LISTNODE *next;
  int data;
}LISTNODE;


LISTNODE *find_lastk(LISTNODE *root, const int k)
{
  LISTNODE *p_before;
  LISTNODE *p_after;
  int i,j;
  p_before = p_after = root;
  i = j = 0;
  while(p_after){
    if(i<k) {
      p_after=p_after->next;
      ++i;
    }
    else {
      p_after = p_after->next;
      p_before = p_before->next;
    }
  }
  if(i<k) return NULL;
  return p_before;
}

main()
{
  LISTNODE *root;
  LISTNODE *p;
  LISTNODE *q;
  int i,j;
  root = (LISTNODE*) malloc(sizeof(LISTNODE));
  if(root==NULL){
    perror("out of memory!");
    exit(-1);
  }
  p = root;
  root->next = NULL;
  for( i = 0; i < 100; ++i){
    q = (LISTNODE*) malloc(sizeof(LISTNODE));
    if(q == NULL){
      perror("out of memory");
      exit(-1);
    }
    q->next = root->next;
    root->next = q;
    q->data = i;
  }
  q = find_lastk(root,100);
  printf("%d\n",q->data);
}

