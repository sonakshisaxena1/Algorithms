#include<bits/stdc++.h>
using namespace std;
int x = -1;

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

int checkSum(Node *node)
{
	int left_data = 0;
	int right_data = 0;

	if(node == NULL || (node->left == NULL && node->right == NULL))
		return 1 ;

	if(node->left == NULL)
		left_data = 0;
	else
		left_data = node->left->data;

	if(node->right == NULL)
		right_data = 0;
	else
		right_data = node->right->data;

	if((left_data + right_data == node->data) && 
		checkSum(node->left) &&
		checkSum(node->right))
	
		return 1;
	
	else
		return 0;

	

	return x;
}
int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
  Node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(checkSum(root) == 1)
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  getchar();
  return 0;
}