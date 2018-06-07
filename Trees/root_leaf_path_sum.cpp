#include<bits/stdc++.h>
using namespace std;
int p[1000];

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

bool checksum(struct node* node, int sum)
{
	if(node == NULL && sum == 0)
		return true;

	else
	  {
	    bool ans = 0;  
	  
	    int subSum = sum - node->data;
	
	    if ( subSum == 0 && node->left == NULL && node->right == NULL )
	      return 1;
	  
	    if(node->left)
	      ans = ans || checksum(node->left, subSum);

	    if(node->right)
	      ans = ans || checksum(node->right, subSum);
	  
	    return ans;
	  }
}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);
	int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
 
  if(checksum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);
 
  getchar();
  return 0;
}