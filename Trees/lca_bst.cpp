/* ****** Lowest Common Ancestor in BST  ******/
#include<iostream>
using namespace std;
int p[1000];

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

struct node* lca(struct node* node, int a, int b)
{
	while(node!=NULL)
	{
		if(node->data > a && node->data > b)
			node = node->left;

		else if( node->data < a && node->data < b)
			node = node->right;
		else
			break;
	}

	return node;
}


int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);

  	struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    getchar();
    return 0;
}