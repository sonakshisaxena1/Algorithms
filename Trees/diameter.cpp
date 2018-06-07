#include<bits/stdc++.h>
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
	return (1+ max(height(node->left), height(node->right)));
}

int diameter(struct node* node)
{
	int left_subtree = height(node->left);
	int right_subtree = height(node->right);
	return (1+left_subtree+right_subtree);
}

int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout); 
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
  getchar();
  return 0;
}