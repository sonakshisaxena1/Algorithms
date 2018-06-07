#include<iostream>
using namespace std;
int p[1000];

struct node{
	int data;
	struct node* left;
	struct node* right;

};

struct node* newNode(int data)
{
	struct node* root = new struct node;
	root->data= data;
	root-> left = NULL;
	root -> right = NULL;
	return root;
}

void printPath(struct node* node, int len, int p[])
{
	if (node == NULL)
		return;

	p[len] = node->data;
	len++;

	if(node->left == NULL && node->right == NULL)
		{
			for(int i = 0;i < len; i++)
				cout<< p[i] << " ";
			cout << endl;
		} 
	else
	{
		printPath(node->left, len, p);
		printPath(node->right, len, p);
	}
}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	struct node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 
 
 
  	printPath(root, 0, p);
 
	
	return 0;
}