#include<iostream>
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

int size(struct node* node)
{
	if(node == NULL)
		return 0;
	else
		return size(node->left)+1+size(node->right);
}

int main()
{
	struct node* root = newNode(7);
	root->left = newNode(9);
	root->right = newNode(110);
	root->right->left = newNode(123);
	root->left->right= newNode(10);
	cout << size(root);
	return 0;
}