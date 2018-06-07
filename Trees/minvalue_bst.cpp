#include<iostream>
using namespace std;

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

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return(newNode(data));
	else
	{
		if(node->data <= data)
			node->right = insert(node->right, data);
		else
			node->left = insert(node->left , data);

	}

	return node;
}


int minValue(struct node* node)
{
	struct node* current_node = node;
	while(current_node->left !=NULL)
	{
		current_node = current_node->left;

	}

	return current_node->data;
}

int main()
{
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
  struct node* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);  
 
  printf("Minimum value in BST is %d", minValue(root));
  
  return 0;    
}