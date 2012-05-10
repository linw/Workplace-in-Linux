/*
 * =====================================================================================
 *
 *       Filename:    006_判断整数序列是不是二元查找树的后序遍历结果.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-18 20:06:20
 *       Compiler:    gcc
 *       Description: 
 *              题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。
 *                    如果是返回true，否则返回false。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
typedef struct BiNode
{
    int data;
    BiNode* left;
    BiNode* right;
}BiNode,*Tree;
static int n_lin = 0;
void create_tree(Tree& root){
    int i;
    cin>>i;
    if(i == -1) root = NULL;
    else{
        root = new BiNode;
        root->data = i;
        create_tree(root->left);
        create_tree(root->right);
    }
    return;
}

void destory_tree(Tree& root){
    if(root == NULL) return;
    else {
        destory_tree(root->left);
        destory_tree(root->right);
        delete root;
        root = NULL;
    }
}

void print_tree(const Tree& root){
    if(root == NULL) {if(n_lin > 0)n_lin--;return ;}
    n_lin++;
    int i = 0;
    while(i++<n_lin)
        cout<<" "; 
    cout<<root->data<<endl;
    print_tree(root->left);
    print_tree(root->right);
}



bool verify_squence_of_BST(int a[], const Tree& t, const int size_a, int& i){
    
}

int main()
{
    Tree root = NULL;
    create_tree(root);
    int a[3] = {5,7,6};
    int i = 0;
    // bool flag = verify_squence_of_BST(a,root,3,i);
    // if(flag) cout<<"hello world"<<endl;
    print_tree(root);
    destory_tree(root);
    return 0;
}
// #include "stdio.h"
// main()
// {
//     char a[] = "\"Blunder\?\?!\?\?\"";
//     printf("%s\n", a);
//     return 0;
// }
