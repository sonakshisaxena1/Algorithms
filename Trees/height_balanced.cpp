// Check if the Binary tree is height-balanced

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
int height(Node *node)
{
	if(node == NULL)
		return 0;
	return(1+max(height(node->left), height(node->right)));

}
int isbalanced(Node * node)
{
	if (node == NULL)
		return 1;

	int x = height(node->left)- height(node->right);
	
	if( abs(x) <=1 &&isbalanced(node->left) && isbalanced(node->right))
		return 1;
	return 0;
}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout); 
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    root->right->right = newNode(17);
 
    if(isbalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
    getchar();
    return 0;
}
