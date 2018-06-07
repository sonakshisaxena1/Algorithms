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

int height(struct node* node)
{
	if(node == NULL)
		return 0;
	else
		return 1+max(height(node->left), height(node->right));
}

int main()
{

	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    cout<< "Max Height/ Depth of tree is: "<<height(root);
   
    getchar();
    return 0;
}