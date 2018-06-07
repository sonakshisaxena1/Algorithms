//Printing the sorted order of an array that represents a BST using inorder traversal

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int start, int end)
{
	if(start > end)
		return;

	printArray(arr, 2*start+1, end);
	cout << arr[start] << " ";
	printArray(arr, 2*start+2, end);

}

int main()
{
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
  int arr[] = {4, 2, 5, 1, 3};
  int arr_size = sizeof(arr)/sizeof(int);
  printArray(arr, 0, arr_size-1);
  return 0;
}