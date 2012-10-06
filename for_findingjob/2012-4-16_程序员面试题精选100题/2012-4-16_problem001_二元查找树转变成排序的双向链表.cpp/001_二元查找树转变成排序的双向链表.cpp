/*
 * =====================================================================================
 *
 *       Filename:    001_二元查找树转变成排序的双向链表.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 11:28:54
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
  int data;
  BiTNode* left;
  BiTNode* right;
}BiTNode, *BiTree;

/*
 * =====================================================================================
 * 在二叉查找树中查找元素i，如果找到返回true，结果由res带回；如果没有找到返回false，res
 * 带回最后的位置。
 *
 * =====================================================================================
 */
bool SearchBST(BiTree root, int i, BiTree &parent, BiTree &res){
  res = root;
  parent = root;
  while(res != NULL){
    parent = res;
    if(i < res->data){
      res = res->left;
    }
    else if(i > res->data){
      res = res->right;
    }
    else{
      break; 
    }
  }
  if(res == NULL) return false;
  else return true;

}

void InsertBST(BiTree &root, int i){
  BiTree parent = NULL;
  BiTree res = NULL;
  BiTree elem = new BiTNode();
  elem->data = i;
  elem->left = NULL;
  elem->right = NULL;
  if(root == NULL) {
    root = elem;
    return;
  }
  if(SearchBST(root,i,parent,res)){
    elem->left = res->left;
    res->left = elem;
  }
  else{
    if(i<parent->data)
      parent->left = elem;
    else if(i > parent->data){
      parent->right = elem;
    }
  }
}

void CreateBST(BiTree& root){
  cout<<"start create BST, please put in numbers to create BST"<<endl;
  int i;
  while(cin>>i){
    InsertBST(root, i);
  }
}

void printBST(const BiTree root){
  if(root == NULL) return;
  cout<<root->data<<" ";
  printBST(root->left);
  printBST(root->right);
}

void DestoryBST(BiTree& root){
  if(root != NULL){
    DestoryBST(root->left);
    DestoryBST(root->right);
    delete root;
    root = NULL;
  }
}

// 思路一：当我们到达某一结点准备调整以该结点为根结点的子树时，先调整其左子树将左子树
// 转换成一个排好序的左子链表，再调整其右子树转换右子链表。最近链接左子链表的最右结点（左子树的
// 最大结点）、当前结点和右子链表的最左结点（右子树的最小结点）。从树的根结点开始递归调整所有结点。
BiTree convert_BiTree_to_Delist(BiTree& root, bool asleft){
  if(!root) return NULL;
  BiTree tl = NULL;
  BiTree tr = NULL; 
  if(root->left)
    tl = convert_BiTree_to_Delist(root->left,true);
  if(tl){
    tl->right = root;
    root->left = tl;
  }
  if(root->right)
    tr = convert_BiTree_to_Delist(root->right, false);
  if(tr){
    tr->left = root;
    root->right = tr;
  }
  BiTree tmp = root;
  if(asleft){
    tmp = root->left;
    if(!tmp) return root;
    while(tmp->right)
      tmp = tmp->right;
  }
  else {
    tmp = root->right;
    if(!tmp) return root;
    while(tmp->left)
      tmp = tmp->left;
  }
  return tmp;
};


// 思路二：我们可以中序遍历整棵树。按照这个方式遍历树，比较小的结点先访问。如果我们每
// 访问一个结点，假设之前访问过的结点已经调整成一个排序双向链表，我们再把调整当前结点的指针将其
// 链接到链表的末尾。当所有结点都访问过之后，整棵树也就转换成一个排序双向链表了。
void convert_BiTree_to_Delist_2(BiTree root, BiTree& last_in_list){
  if(!root) return;
  BiTree pCurrent = root;

  if(pCurrent->left != NULL)
    convert_BiTree_to_Delist_2(pCurrent->left, last_in_list);
  pCurrent->left = last_in_list;
  if(last_in_list != NULL)
    last_in_list->right = pCurrent;
  last_in_list = pCurrent;
  if(pCurrent->right != NULL)
    convert_BiTree_to_Delist_2(pCurrent->right, last_in_list);
}


int main()
{
  BiTree root = NULL;
  //    root->data = 10;
  //    root->left = NULL;
  //    root->right = NULL;
  // InsertBST(root,10);
  // InsertBST(root,5);
  // InsertBST(root, 15);
  CreateBST(root);
  cout<<"create finished!"<<endl;
  // cout<<(root->data)<<(root->left->data)<<endl;
  // cout<<root->right->data<<endl;
  // printBST(root);
  // BiTree head = convert_BiTree_to_Delist(root, true);
  BiTree head = NULL;
  convert_BiTree_to_Delist_2(root,head);
  BiTree preHead = NULL;
  while(head){
    cout<<head->data<<endl;
    preHead = head;
    head = head->left;
  }
  head = preHead;
  while(head){
    cout<<head->data<<endl;
    head = head->right;
  }
  DestoryBST(root);
  return 0;
}
