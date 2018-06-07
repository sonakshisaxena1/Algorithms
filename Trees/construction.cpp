#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int idata)
{
	struct node *node = new struct node;
	node->data = idata;
	node->left = NULL;
	node->right = NULL;
	return node;
	
}

int main()
{
	struct node* root = newNode(9);
	root->left = newNode(8);
	root->right = newNode(10);
	root->left->left = newNode(7);
	cout << root->left->left->data;
}