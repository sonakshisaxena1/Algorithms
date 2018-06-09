#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int coin[m+1];
	for(int i = 1; i<=m; i++)
		cin >> coin[i];
 
	int dp[2][n+1];
	for(int i = 0; i<=n; i++)
		dp[0][i] = 0;
	dp[0][0] = 1;
 
	bool flag = true;
 
	for(int i = 1; i<=m; i++)
	{
		for(int j = 0; j<=n; j++)
		{
			dp[flag][j] = dp[!flag][j];
			if(j >= coin[i])
				dp[flag][j] += dp[flag][j-coin[i]];
		}
		flag = !flag;
	}
 
	cout << dp[!flag][n] << "\n";
 
	return 0;
}