#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


struct BSTreeNode // a node in the binary search tree
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

/////////////////////////////////////////////////////////////////////
//
// Covert a sub binary-search-tree into a sorted double-linked list
// Input: pNode - the head of the sub tree
// asRight - whether pNode is the right child of its parent
// Output: if asRight is true, return the least node in the sub-tree
// else return the greatest node in the sub-tree
/////////////////////////////////////////////////////////////////////
BSTreeNode* ConvertNode(BSTreeNode* pNode, bool asRight)
{
	if (!pNode)
		return NULL;
	BSTreeNode *pLeft = NULL;
	BSTreeNode *pRight = NULL;
	// Convert the left sub-tree
	if (pNode->m_pLeft)
		pLeft = ConvertNode(pNode->m_pLeft, false );
	// Connect the greatest node in the left sub-tree to the current node
	if (pLeft)
	{
		pLeft->m_pRight = pNode;
		pNode->m_pLeft = pLeft;
	}
	// Convert the right sub-tree
	if (pNode->m_pRight)
		pRight = ConvertNode(pNode->m_pRight, true );
	// Connect the least node in the right sub-tree to the current node
	// Connect the least node in the right sub-tree to the current node
	if (pRight)
	{
		pNode->m_pRight = pRight;
		pRight->m_pLeft = pNode;
	}
	BSTreeNode *pTemp = pNode;
	// If the current node is the right child of its parent,
	// return the least node in the tree whose root is the current node
	if (asRight)
	{
		while (pTemp->m_pLeft)
			pTemp = pTemp->m_pLeft;
	}
	// If the current node is the left child of its parent,
	// return the greatest node in the tree whose root is the current node
	else
	{
		while (pTemp->m_pRight)
			pTemp = pTemp->m_pRight;
	}
	return pTemp;
}
/////////////////////////////////////////////////////////////////////
//
// Covert a binary search tree into a sorted double-linked list
// Input: the head of tree
// Output: the head of sorted double-linked list
/////////////////////////////////////////////////////////////////////
//
BSTreeNode* Convert(BSTreeNode* pHeadOfTree)
{
	// As we want to return the head of the sorted double-linked list,
	// we set the second parameter to be true
	return ConvertNode(pHeadOfTree, true );
}



bool SearchBST(BSTreeNode* root, int i, BSTreeNode* &parent, BSTreeNode* &res){
    res = root;
    parent = root;
    while(res != NULL){
        parent = res;
        if(i < res->m_nValue){
            res = res->m_pLeft;
        }
        else if(i > res->m_nValue){
            res = res->m_pRight;
        }
        else{
            break; 
        }
    }
    if(res == NULL) return false;
    else return true;

}

void InsertBST(BSTreeNode* &root, int i){
    BSTreeNode* parent = NULL;
    BSTreeNode* res = NULL;
    BSTreeNode* elem = new BSTreeNode();
    elem->m_nValue = i;
    elem->m_pLeft = NULL;
    elem->m_pRight = NULL;
    if(root == NULL) {
        root = elem;
        return;
    }
    if(SearchBST(root,i,parent,res)){
        elem->m_pLeft = res->m_pLeft;
        res->m_pLeft = elem;
    }
    else{
        if(i<parent->m_nValue)
            parent->m_pLeft = elem;
        else if(i > parent->m_nValue){
            parent->m_pRight = elem;
        }
    }
}

void CreateBST(BSTreeNode* &root){
    cout<<"start create BST, please put in numbers to create BST"<<endl;
    int i;
    while(cin>>i){
        InsertBST(root, i);
    }
}


void DestoryBST(BSTreeNode* &root){
    if(root != NULL){
        DestoryBST(root->m_pLeft);
        DestoryBST(root->m_pRight);
        delete root;
        root = NULL;
    }
}

int main()
{
	BSTreeNode* root = NULL;
    CreateBST(root);
	root = Convert(root);
	while(root != NULL){
		cout<<root->m_nValue<<endl;
		root = root->m_pRight;
	}
    DestoryBST(root);

	return 0;
}