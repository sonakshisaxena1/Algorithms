//Kadane's algorithm
//tracks max sum contagious segment among all positive segments
//O(n)

#include<bits/stdc++.h>
using namespace std;
vector<int>a;

int maxSumSubarray()
{
	int max_end = 0, max_so_far = 0;
	int start = 0, end = 0, s = 0;
	for(int i = 0; i < a.size(); i++)
	{
		max_end += a[i];
		if(max_so_far < max_end)
		{
			max_so_far = max_end;
			start = s;
			end = i;
			
		}
		if(max_end < 0)
		{
			max_end = 0;
			s = i + 1;
		}

	}

	cout << "The start index of the subarray is: " << start << "\nThe end index is: " << end << "\n";
	return max_so_far;
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n; 
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << maxSumSubarray() << " is the length" ;
	return 0;

}