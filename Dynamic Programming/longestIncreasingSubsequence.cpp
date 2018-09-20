//O(n*n)
//DP
#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int longestIncreasingSubsequence()
{
	int LIS[a.size()];
	for(int i = 0; i < a.size(); i++)
		LIS[i] = 1;
	for(int i = 1; i < a.size(); i++)
		for(int j = 0; j <= i-1; j++)
			if(a[i] > a[j] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j]+1;
	int max_value = 0;
	for(int i = 0; i < a.size(); i++)
		max_value = max(max_value, LIS[i]);
	return max_value;
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
	cout << longestIncreasingSubsequence();
	
}