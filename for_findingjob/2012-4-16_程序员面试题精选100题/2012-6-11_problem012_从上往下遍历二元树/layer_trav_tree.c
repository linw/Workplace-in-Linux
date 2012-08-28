/*
 * =====================================================================================
 *
 *       Filename:    find_mirror.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-11 22:29:40
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: 
 *             题目: 输入一个二元树，从上往下按层次打印出树的节点
 *             理解: 就是一个树的按层遍历,这里可以使用一个队列实现
 *
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
  struct Node *left;
  struct Node *right;
  int data;
}TreNode,Node;

// 现在实现一个队列
typedef struct QNode{
  struct QNode *next;
  struct QNode *pre;
  Node *elem;
}QNode;

typedef struct Queue{
  QNode *head;
  QNode *tail;
}Queue;


Queue *init_queue()
{
  Queue *new_queue;
  new_queue = (Queue*) malloc(sizeof(Queue));
  if(new_queue == NULL){
    return NULL;
  }
  new_queue->head = new_queue->tail = NULL;
  return new_queue;
}

void free_queue(Queue *queue)
{
  while(pop(queue));
  free(queue);
}

void push(Queue *queue, const Node* elem)
{
  QNode *p;
  assert(q);
  p = (QNode *) malloc(sizeof(QNode));
  if(p == NULL){
    perror("Out of memory!");
    exit(-1);
  }
  p->elem = elem;
  if(queue->head == NULL){
    queue->head = queue->tail = p;
    if(queue->head == NULL){
      perror("out of memory");
      exit(-1);
    }
    p->pre = p->next = NULL;
  }
  else {
    queue->head->pre = p;
    p->next = queue->head;
    queue->head = p;
  }
}

int pop(Queue *queue)
{
  Node *p;
  // Node elem;
  if(queue->tail){ // 尾节点不为空
    elem = *(queue->elem);
    p = queue->tail;
    if(queue->tail == queue->head){
      queue->tail = queue->head = NULL;
    }
    free(p);
    return 1;
  }
  else {
    printf("no item in queue!\n");
    return -1;
    //   eixt(-1);
  };
}

Node *head(const Queue *queue)
{
  return queue->head;
}
Node *tail(const Queue *queue)
{
  return queue->head;
}




// 可以使用一个队列实现
void trav_tree_layer(TreNode *root)
{
  QNode *queue;
  queue = init_queue();
  
  free_queue(queue);
} 


main()
{
}
