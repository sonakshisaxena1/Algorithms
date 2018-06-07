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

int countLeaf(Node* node)
{
	if(node == NULL)       
    return 0;

	if(node->left == NULL && node->right==NULL)      
	    return 1;            
	else
    return countLeaf(node->left)+
           countLeaf(node->right);   
}


int main()
{
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout); 
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);    
   
 
  printf("Leaf count of the tree is %d", countLeaf(root));
   
  getchar();
  return 0;
}
