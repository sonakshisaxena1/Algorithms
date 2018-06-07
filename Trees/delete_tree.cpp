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


void deleteTree(struct node* node) 
{
    if (node == NULL) 
    	return;

    deleteTree(node->left);
    deleteTree(node->right);
   
  
    cout << " Deleting node: ", node->data << endl;
    free(node);
} 

int main()
{

	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root);  
    root = NULL;
   
   
    return 0;
}