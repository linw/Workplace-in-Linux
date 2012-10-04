/*
 * =====================================================================================
 *
 *       Filename:    get_tree_depth.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-09-28 13:04:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>
typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

int get_tree_depth(Node* tree)
{
  int l_dep,r_dep;
  if(NULL == tree){
    return 0;
  }
  l_dep = r_dep = 1;
  if(tree->left != NULL){
    l_dep = get_tree_depth(tree->left) + 1;
  }
  if(tree->right != NULL){
    r_dep = get_tree_depth(tree->right) + 1;
  }
  return l_dep>r_dep?l_dep:r_dep;
}

main()
{
  Node a,b,c,d,e,f;
  Node g;
  a.data = 0;
  a.left = &b;
  a.right = &c;
  b.data = 1;
  b.left = &d;
  b.right = NULL;
  c.data = 2;
  c.left = &e;
  c.right = NULL;
  d.data = 3;
  d.left = NULL;
  d.right = NULL;
  e.data = 4;
  e.left = &f;
  e.right = NULL;
  f.data = 5;
  f.left = &g;
  f.right = NULL;
  g.data = 6;
  g.left = g.right = NULL;
  printf("%d\n",get_tree_depth(&a));
  return 0;
}
