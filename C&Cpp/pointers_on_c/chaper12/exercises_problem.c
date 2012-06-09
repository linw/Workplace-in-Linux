/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 22:26:14
 *       Last Edit:   2012-6-5 20:31:22
 *       Compiler:    gcc
 *       Description: exercises in chaper12
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
/* extern struct NODE; */
/* extern struct DNODE; */
// list
typedef struct NODE{
  struct NODE *next;
  int elem;
}NODE;

// dlist
typedef struct DNODE{
  struct DNODE *fwd;
  struct DNODE *bwd;
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

// problem 2: 寻找单链表中的节点
NODE * find_list(NODE const *root, int elem)
{
  while(root){
    if(root->elem == elem) return root;
    root = root->next;
  }
  return NULL;
}


// problem 3: 重写dll_insert
int dll_insert(DNODE *head, DNODE *tail, int value)
{
  DNODE *new_node;
  DNODE *this;
  DNODE *next;
  /* if(tail->elem == value) return 0; */
  /* for(this = head; this != tail; this = this->fwd){ */
  /*   if(this->elem == value) return 0; */
  /*   if(this->elem > value) */
  /*     break; */
  /* } */
  for(this = head; this != NULL; this = this->fwd){
    if(this->elem == value) return 0;
    if(this->elem > value) break;
  }
  new_node = (DNODE *) malloc(sizeof(DNODE));
  if(new_node == NULL) 
    return -1;
  new_node->elem = value;
  if(this == NULL){
    tail->fwd = new_node;
    head->bwd->bwd = new_node;
    new_node->bwd = tail;
    new_node->fwd = NULL;
  }
  else {
    new_node->bwd = this->bwd;
    new_node->fwd = this;
    this->bwd->fwd = new_node;
    this->bwd = new_node;
  }
  return 1;
}


// problem 4: 逆转一个单链表
NODE * sll_reverse(NODE *first)
{
  NODE *new_first;
  NODE *p_tmp;
  /* NODE *p_tmp1; */
  new_first = NULL;
  while(first){
    if(new_first == NULL){
      new_first = first;
      first = first->next;
      new_first->next = NULL;
      continue;
    }
    p_tmp = new_first;
    new_first = first;
    first = first->next;
    new_first->next = p_tmp;
    /* first = first->next; */
  }
  return new_first;   
}

// problem 5: 编写函数从一个单链表中删除一个节点
int sll_remove(NODE **rootp, NODE *node)
{
  NODE *this;
  NODE *before;
  assert(node != NULL);
  if(*rootp == node){
    free(node);
    *rootp = NULL;
    return 1;
  }
  for(this = (*rootp)->next,before = *rootp; this;){
    if(this == node){
      before->next = this->next;
      free(node);
      return 1;
    }
    before = this;
    this=this->next;
  }
  return 0;  
}


// problem 6: 编写函数从双链表中移除一个节点
int dll_remove(DNODE *rootp, DNODE *node)
{
  DNODE *this;
  if(node == rootp->fwd){
    rootp->fwd = node->fwd;
    node->fwd->bwd = NULL;
    free(node);
    return 1;
  }
  if(node == rootp->bwd){
    rootp->bwd = node->bwd;
    node->bwd->fwd = NULL;
    free(node);
    return 1;
  }
  for(this = rootp->fwd->fwd; this->fwd; this=this->fwd){
    if(this == node) {
      node->fwd->bwd = node->bwd;
      node->bwd->fwd = node->fwd;
      free(node);
      return 1;
    }
  }
  return 0;
}


// problem 7: 编写函数把新单词加入到到索引表中
// 没看明白具体题意，看看再说吧


main()
{
  int i;
  NODE *p;
  NODE *root;
  root = p = NULL;
  for(i = 0; i < 10; ++i){
    p = NULL;
    p = (NODE *) malloc(sizeof(NODE));
    if(p == NULL) {
      printf("Out of memory!\n");
      exit(-1);
    }
    p->elem = i;
    p->next = NULL;
    p->next = root;
    root = p;
  }
  p = root;
  p = sll_reverse(root);
  root = p;
  while(p){
    printf("%d ",p->elem);
    p = p->next;
  }
  printf("%d\n",traverse_count_list(root));
  printf("%f\n",sqrt(10));
}
