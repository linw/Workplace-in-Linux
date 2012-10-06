/*
 * =====================================================================================
 *
 *       Filename:    find_path.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-05 13:27:12
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct StackNode{
  int value;
  struct StackNode *next;
}StackNode;

StackNode *init_stack()
{
  StackNode* head = NULL;
  head = (StackNode*)malloc(sizeof(StackNode));
  if(head == NULL){
    return NULL;
  }
  head->value = 0;
  head->next = NULL;
  return head;
}

StackNode *top_stack(const StackNode* head)
{
  assert(head);
  return head->next;
}

void push_stack(StackNode* head, int value)
{
  assert(head);
  StackNode* new_node = NULL;
  new_node = (StackNode*)malloc(sizeof(StackNode));
  assert(new_node);
  new_node->value = value;
  new_node->next = head->next;
  head->value += 1;
  head->next = new_node;
}

void pop_stack(StackNode *head)
{
  assert(head);
  StackNode* del_node;
  if(head->next != NULL){
    del_node = head->next;
    head->next = head->next->next;
    head->value -= 1;
    free(del_node);
  }
}

int size_stack(const StackNode* head)
{
  return head->value;
}

void print_stack(const StackNode* head)
{
  assert(head);
  StackNode* tmp;
  tmp = head->next;
  while(tmp){
    printf("%d->",tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

void release_stack(StackNode **head)
{
  StackNode *tmp;
  if(*head == NULL){
    return;
  }
  while(size_stack(*head)){
    pop_stack(*head);
  }
  free(*head);
  *head = NULL;
}




typedef struct TreeNode{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

void find_path(TreeNode *tree_root,
	       int expected,
	       StackNode *path,
	       int *current)
{
  int isleaf;
  if(!tree_root){
    return;
  }
  *current += tree_root->value;
  push_stack(path, tree_root->value);
  isleaf = 1|| (!tree_root->left&&!tree_root->right);
  if((*current) == expected && isleaf){
    print_stack(path);
  }
  if(tree_root->left){
    find_path(tree_root->left, expected, path, current);
  }
  if(tree_root->right){
    find_path(tree_root->right, expected, path, current);
  }
  *current -= tree_root->value;
  pop_stack(path);
}



int
main(void)
{
  /* StackNode *head = NULL; */
  /* int i; */
  /* head = init_stack(); */
  /* for(i = 0; i < 10; ++i){ */
  /*   push_stack(head, i); */
  /* } */
  /* printf("stack size: %d\n", size_stack(head)); */
  /* while(size_stack(head)){ */
  /*   printf("elem is %d\n",top_stack(head)->value); */
  /*   pop_stack(head); */
  /* } */
  /* release_stack(&head); */
  /* printf("stack head address is:%lx\n",head); */

  StackNode *head = NULL;
  TreeNode a1,a2,a3,a4,a5;
  int cur;
  cur = 0;
  head = init_stack();
  a1.value = 1;
  a2.value = 2;
  a3.value = 6;
  a4.value = 4;
  a5.value = 4;
  a1.left = &a2;
  a1.right = &a3;
  a2.left = &a4;
  a2.right = &a5;
  a4.left = a4.right = a5.left = a5.right = a3.left = a3.right = NULL;
  find_path(&a1,7,head,&cur);  
  exit(0);  
}

