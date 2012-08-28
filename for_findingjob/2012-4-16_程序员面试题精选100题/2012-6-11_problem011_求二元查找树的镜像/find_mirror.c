/*
 * =====================================================================================
 *
 *       Filename:    find_mirror.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-11 16:42:50 
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: 
 *             题目: 输入一颗二元查找树,将该树转换为它的镜像,即在转换后的二元查找
 *                   树中,左子树的结点都大于右子树的结点。用递归和循环两种方法完
 *                   成树的镜像转换。
 *
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct TreNode{
  struct TreNode *left;
  struct TreNode *right;
  int data;
}Node,TreNode;

void  mirror_tre(TreNode *root)
{
  Node *p;
  if(root == NULL) 
    return;
  p = root->left;
  root->left = root->right;
  root->right = p;
  mirror_tre(root->left);
  mirror_tre(root->right);
}




main()
{
  Node root;
  Node left;
  Node right;

  root.left = &left;
  root.right = &right;
  left.left = NULL;
  left.right = NULL;
  right.left = NULL;
  right.right = NULL;
  root.data = 1;
  left.data = 2;
  right.data = 3;
  mirror_tre(&root);
  printf("%d,%d,%d\n",root.data,root.left->data,root.right->data);
}


