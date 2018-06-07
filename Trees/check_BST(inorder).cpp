//Checking BST using inorder traversal
//Do inorder traversal and store it in a temp array. If the array is sorted then it is BST else not
//Space can be optimised by having a previous pointer rather than an array.

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left, *right;
};

struct node* newNode(int data)
{
	node* root = new struct node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

bool isBST(struct node* root)
{
    static struct node *prev = NULL;
     
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}

int main()
{	
	
  	freopen("out.out", "w", stdout); 
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
 
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}

