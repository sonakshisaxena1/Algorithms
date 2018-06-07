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
	struct node* root = new struct node;
	root->data = idata;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void preorder(struct node* node)
{
	if(node == NULL)
		
			return;

	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
	

}

void postorder(struct node* node)
{
	if(node == NULL)
		return;

	
	postorder(node->left);
	postorder(node->right);

	cout << node -> data << " "; 
}

void inorder(struct node* node)
{
	if(node == NULL)
		return;
	inorder(node->left);
	cout << node -> data << " ";

	inorder(node->right);

	 
}


int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);

     printf("\nPreorder traversal of binary tree is \n");
     preorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     inorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     postorder(root);
 
     getchar();
     return 0;
}