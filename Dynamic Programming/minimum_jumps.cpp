/* Given an array of integers where each element represents the max number of steps that
 can be made forward from that element. Write a function to return the minimum number 
 of jumps to reach the end of the array (starting from the first element). If an element
 is 0, then cannot move through that element.*/

#include<bits/stdc++.h>
using namespace std;


int minJumps(int arr[], int n)
{
	int jumps[n];

	if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;
    
	for (int i  = 1; i<n; i++)
	{
		jumps[i] = INT_MAX;

		for(int j = 0; j < i; j++)

		{
			if(i <= j + arr[j] && jumps[j] != INT_MAX)
				{
					jumps[i] = min(jumps[i], jumps[j] + 1);
					break;
				}

		}

	}
	return jumps[n-1];

}

int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}