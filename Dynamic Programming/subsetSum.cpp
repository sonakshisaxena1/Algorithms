#include<bits/stdc++.h>
using namespace std;
vector<int>a;

int subsetSum(int sum)
{
	bool dp[a.size() + 1][sum + 1];
	for(int i = 0; i < a.size() + 1; i++)
		dp[i][0] = true;
	for(int j = 1; j <= sum; j++)
		dp[0][j] = false;
	for(int i = 1; i <= a.size(); i++)
		for(int j = 1; j <= sum; j++)
		{
			if(j < a[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j - a[i-1]];
		}
	return dp[a.size() + 1][sum+1];

}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n,sum;
	cin >> n >> sum;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	if(subsetSum(sum))
		cout << "yes";
	else
		cout << "no";
	return 0;
}