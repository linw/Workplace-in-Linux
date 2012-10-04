/*
 * =====================================================================================
 *
 *       Filename:    reverse_list.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-27 22:16:13
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: Á´±íµÄÄæÐò
 * =====================================================================================
 */
#include <stdio.h>
#include <assert.h>
typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* reverse(Node* root)
{
  assert(root);
  Node* current;
  Node* pre;
  Node* nex;
  current = root;
  pre = NULL;
  nex = current->next;
  while(NULL != nex){
    current->next = pre;
    pre = current;
    current = nex;
    nex = nex->next;
  }
  current->next = pre;
  return current;
}

main(int argv, char* args[])
{
  Node a1,a2,a3,a4,a5;
  Node* p;
  a1.data = 1;
  a2.data = 2;
  a3.data = 3;
  a4.data = 4;
  a5.data = 5;
  a1.next = &a2;
  a2.next = &a3;
  a3.next = &a4;
  a4.next = &a5;
  a5.next = NULL;
  p = &a1;
  while(p){
    printf("%d ",p->data);
    p = p->next;
  }
  p = &a1;
  p = reverse(p);
  while(p){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("%d\n",EOF);
  try{
    int *kkk = new int[-1];
  }
  catch(...){
    printf("Error!\n");
  }
  printf("main finish\n");
  /* int *tt = new int[-1]; */
  /* if(NULL == tt){ */
  /*   printf("error!\n"); */
  /* } */
  /* getchar(); */
}


