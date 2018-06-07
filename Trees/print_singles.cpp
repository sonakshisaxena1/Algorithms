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

void singles(struct node* node)
{
	if(node == NULL)
		return;

	if(node->left!=NULL && node->right!=NULL)
	{
		singles(node->left);
		singles(node->right);
	}

	else if(node->right!=NULL)
		{
			cout << node->right->data << " ";
			singles(node->right);
		}

	else if(node->left!=NULL)
		{
			cout << node->left->data << " ";
			singles(node->left);
		}

}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    singles(root);
    return 0;
}