#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
bool printPath(struct node* node, struct node* targetNode)
{
	if(node == NULL)
		return false;

	if(node == targetNode || printPath(node->left, targetNode) || printPath(node->right, targetNode))
	{
		cout << node->data << " ";
		return true;
	}
	return false;
}
void getTarget(struct node *node, int *maxSumRef, int currSum, struct node **targetNode)
{
	if(node == NULL)
		return;

	currSum += node->data;
	if(node->left == NULL && node->right == NULL)
	{
		if(currSum > *maxSumRef)
		{
			*maxSumRef = currSum;
			*targetNode = node;
		}
	}

	getTarget(node->left, maxSumRef, currSum, targetNode);
	getTarget(node->right, maxSumRef, currSum, targetNode);
}
int maxSumPath (struct node *node) 
{ 
  	if(node == NULL)
  		return 0;

  	int maxSumRef = INT_MIN;
  	struct node* targetNode;
  	getTarget(node, &maxSumRef, 0, &targetNode);
  	printPath(node, targetNode);
  	return maxSumRef;
} 
  

struct node* newNode (int data) 
{ 
    struct node *temp = new struct node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  

int main() 
{ 
    struct node *root = NULL; 
  	freopen("test.in", "r", stdin);
  	freopen("test.out", "w", stdout);
    
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(7); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
  
    printf ("Following are the nodes on the maximum "
            "sum path \n"); 
    int sum = maxSumPath(root); 
    printf ("\nSum of the nodes is %d ", sum); 
  
    getchar(); 
    return 0; 
} 