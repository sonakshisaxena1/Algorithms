//Convert an arbitrary Binary Tree to a tree that holds Children Sum Property

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

};

struct Node* newNode(int data)
{
	Node *root = new Node;
	root->data= data;
	root->left = root->right = NULL;
	return root;
}
void increment(struct Node* node, int diff)
{
  
  if(node->left != NULL)
  {
    node->left->data = node->left->data + diff;
    increment(node->left, diff);  
  }

  else if (node->right != NULL) 
  {
    node->right->data = node->right->data + diff;
    increment(node->right, diff);
  }

}


void convertTree(Node* node)
{
	int left_data = 0;
	int right_data = 0;
	int diff;
	if(node == NULL || (node->left == NULL && node->right == NULL))
			return;
	else
	{
		convertTree(node->left);
		convertTree(node->right);
		if (node->left != NULL)
	      left_data = node->left->data;

	    if (node->right != NULL)
	      right_data = node->right->data;
 
	    
	    diff = left_data + right_data - node->data;
	 
	    if (diff > 0)
	       node->data = node->data + diff;
	 
	    if (diff < 0)
	      increment(node, -diff);
	}

}

void printInorder(struct Node* node)
{
  if (node == NULL)
    return;

  printInorder(node->left);
 
  cout<< node->data << " ";

  printInorder(node->right);
}


int main()
{
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout); 
  struct Node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
 
  getchar();
  return 0;
}