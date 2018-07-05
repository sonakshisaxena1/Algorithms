#include<bits/stdc++.h>
using namespace std;
int temp[100];
int len = 0;

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

void inorder(Node* node)
{
	if(node == NULL)
		return;

	if(node->left != NULL)
		inorder(node->left);

	temp[len] = node->data;
	len++;

	if(node->right!=NULL)
		inorder(node->right);

}

int main()
{
	freopen("out.out", "w", stdout);
	struct Node *root;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(10);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    inorder(root);
    temp.sort(0,len );
    for(int i = 0 ; i <len; i++)
    	cout<< temp[i] << " ";
    return 0;
}