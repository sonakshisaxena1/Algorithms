#include<iostream>
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

int size(struct node* node)
{
	if(node == NULL)
		return 0;
	else
		return size(node->left)+1+size(node->right);
}

int identicalTrees(struct node* a, struct node* b)
{
   
    if (a==NULL && b==NULL)
        return 1;
 
    
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    
    return 0;
} 

int main()
{
	struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(identicalTrees(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
}