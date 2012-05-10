/*
 * =====================================================================================
 *
 *       Filename:    004_在二元树中找出和为某一值的所有路径.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-18 17:04:58
 *       Compiler:    gcc
 *       Description: 
 *              题目：输入一个整数和一棵二元树。从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条
 *                   路径。打印出和与输入整数相等的所有路径。
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;
typedef struct BiNode
{
    int data;
    BiNode* left;
    BiNode* right;
}BiNode,*BiTree;



void find_route(const BiTree& root, const int& value, vector<int>& path, int& currentValue){
    // if(root == NULL) return;
    // if(root->data == value){
    //     stack.push_back(root->data);
    //     return;
    // }
    // find_route(root->left, value-root->data, stack);
    // find_route(root->right, value-root->data, stack);
    if(!root)
        return;
    currentValue += root->data;
    path.push_back(root->data);
    bool isLeaf = (!root->left && !root->right);
    if(currentValue == value && isLeaf){
        for (std::vector<int>::iterator i = path.begin(); i != path.end(); ++i)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    if(root->left)
        find_route(root->left,value,path,currentValue);
    if(root->right)
        find_route(root->right,value,path,currentValue);
    currentValue -= root->data;
    path.pop_back();
}

void create_tree(BiTree& root){
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

void destory_tree(BiTree& root){
    if(root == NULL) return;
    else {
        destory_tree(root->left);
        destory_tree(root->right);
        delete root;
        root = NULL;
    }
}

int main(int argc, char const *argv[])
{
    // BiTree root = NULL;
    // root = new BiNode;
    // root->data = 10;
    // root->left = new BiNode;
    // root->right = new BiNode;
    // root->left->data = 5;
    // root->right->data = 12;
    // root->right->left = root->right->right = NULL;

    // root->left->left = new BiNode;
    // root->left->right = new BiNode;
    // root->left->left->data = 4;
    // root->left->right->data = 7;
    // root->left->left->left = root->left->left->right = NULL;
    // root->left->right->left = root->left->right->right = NULL;

    BiTree root = NULL;
    create_tree(root);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;


    vector<int> v;
    // find_route(root, 22, v);
    // for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    // {
    //     cout<<*i<<endl;
    // }

    int currentValue = 0;
    find_route(root,22,v,currentValue);


    destory_tree(root);

    return 0;
}
