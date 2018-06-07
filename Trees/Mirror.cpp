// Create Mirror tree for binary tree

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

void mirror(struct node* node)
{
	if(node == NULL)
		return;
	
	else
	{
		struct node* temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;


	}
}

void inorder(struct node* node)
{
	if(node == NULL)
		return;

	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);

}

int main()
{
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   
  
  cout << "Inorder traversal of the constructed"
           " tree is : ";
  inorder(root);
  cout << endl;
  
   
  
  mirror(root); 
   
  
  cout << "Inorder traversal of the mirror tree"
         " is: ";
  inorder(root);
  cout << endl; 
  
   
  return 0;  
}