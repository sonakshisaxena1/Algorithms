#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

Node* newNode(int data)
{
	Node* root = new struct Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

int checkBST(Node* node)
{
	int left_data, right_data;

	if(node->left == NULL)
		left_data = 0;
	else
		left_data = node->left->data;

	if(node->right == NULL)
		right_data = 0;
	else
		right_data = node->right->data;


	if (node == NULL)
		return 1;

	if(left_data <= node->data && right_data > node->data && checkBST(node->left)
	    && checkBST(node->right))
		
		return 1;


	else
		return 0;
}

int main()
{
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout); 

  struct Node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(checkBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}