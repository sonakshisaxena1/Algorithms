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

int maxWidth(struct node* node)
{
	if(node == NULL)
		return 0;

	
	int result = 0;
	queue < struct node*> q;
	q.push(node);
	while(!q.empty())
	{
		int count = q.size();
		result = max(count,result);
		while(count--)
		{
			struct node* temp = q.front();
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}
	return result;
}

int main()
{
	
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);
  root->right->right->left  = newNode(6);
  root->right->right->right  = newNode(7);
 
  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8
              /  \
             6   7
  */
  printf("Maximum width is %d \n", maxWidth(root));
  getchar();
  return 0;
}