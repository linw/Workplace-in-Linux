/*
 * =====================================================================================
 *
 *       Filename:    find_lowest_parent_tree.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-23 14:03:05
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 在一棵二叉树下,给定两个节点,找到这两个节点的最低的父亲节点
 * =====================================================================================
 */
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
}Node,*BiTree;


int find_lowest_parent_tree(Node* tree, Node* a, Node* b, BiTree *result)
{
  int l,r,m;
  l = r = m = 0;
  if(*result == NULL && tree->left != NULL) {
    l = find_lowest_parent_tree(tree->left,a,b,result);
  }
  if(*result == NULL && tree->left != NULL) {
    r = find_lowest_parent_tree(tree->right,a,b,result);
  }
  if(tree == a || tree == b){
    m = 1;
  }
  if(*result == NULL && m+l+r == 2){
    *result = tree;
  }
  return m || l || r;
}


main(int argv, char* args[])
{
  Node n1,n2,n3,n4,n5,n6,n7;
  BiTree p = NULL;
  n1.data = 0;
  n2.data = 1;
  n3.data = 2;
  n4.data = 3;
  n5.data = 4;
  n6.data = 5;
  n7.data = 6;
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n5.left = &n6;
  n5.right = &n7;
  n4.left = n4.right = NULL;
  n3.left = n4.right = NULL;
  n6.left = n6.right = NULL;
  n7.left = n7.right = NULL;
  find_lowest_parent_tree(&n1,&n4,&n2,&p);
  printf("%d\n",p->data);
  
}
