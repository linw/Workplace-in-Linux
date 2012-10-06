/*
 * =====================================================================================
 *
 *       Filename:    print_list.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-29 16:01:34
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

void print_list(Node* head)
{
  assert(head);
  Node *p;
  p = head;
  while(p){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

void print_list_r(Node* head)
{
  assert(head);
  if(head->next){
    print_list_r(head->next);
  }
  printf("%d ", head->data);
}

Node* reverse_list(Node* head)
{
  Node* pre = NULL;
  Node* cur = head;
  Node* nex = head->next;
  while(nex){
    cur->next = pre;
    pre = cur;
    cur = nex;
    nex = nex->next;
  }
  cur->next = pre;
  return cur;
}


int my_strlen(const char *str)
{
  assert(str);
  if(*str == '\0')
    return 0;
  return my_strlen(str+1)+1;
}

void print_str_r(const char *str)
{
  assert(str);
  if(*str == '\0')
    return ;
  print_str_r(str+1);
  printf("%c",*str);
}


int
main(void)
{
  printf("strlen:%d\n",my_strlen("hello the world!"));
  print_str_r("hello");
  exit(0);
}


/* int main(void) */
/* { */
/*   Node a[10]; */
/*   int i; */
/*   Node *p; */
/*   Node b; */
/*   b.data = 0; */
/*   b.next = NULL; */
/*   for(i = 0; i < 10; ++i){ */
/*     a[i].data = i; */
/*     if(i < 9){ */
/*       a[i].next = &a[i+1]; */
/*     } */
/*     else { */
/*       a[i].next = NULL; */
/*     } */
/*   } */
/*   /\* printf("\n"); *\/ */
/*   /\* for(i = 0; i < 10; ++i){ *\/ */
/*   /\*   printf("%x:%d:%x\n",a+i, a[i].data, a[i].next); *\/ */
/*   /\* } *\/ */
/*   print_list_r(&a[0]); */
/*   p = reverse_list(&a[0]); */
/*   printf("\n"); */
/*   for(i = 0; i < 10; ++i){ */
/*     printf("%x:%d:%x\n",a+i, a[i].data, a[i].next); */
/*   } */
/*   printf("%x\n",p); */
/*   print_list(p); */
/* } */
