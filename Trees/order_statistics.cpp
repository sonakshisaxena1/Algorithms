//Given root of binary search tree and K as input, find K-th smallest element in BST.
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};



struct node* newNode(int idata)
{
	struct node* root = new struct node;
	root->data = idata;
	root->left = NULL;
	root->right = NULL;
	return root;
}