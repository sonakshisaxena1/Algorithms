#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
int minCost(int cost[R][C], int m, int n)
{
	int dp[m+1][n+1];
	dp[0][0] = cost[0][0];

	for(int i = 1 ;i <= m; i++)
		dp[i][0] = dp[i-1][0] + cost[i][0];

	for(int i = 1 ;i <= m; i++)
		dp[0][i] = dp[0][i-1] + cost[0][i];

	for(int i = 1 ;i <= m; i++)
		for(int j = 1 ;j <= n; j++)
			dp[i][j] = min ( min(dp[i-1][j], dp[i][j-1]),
								     dp[i-1][j-1] ) + cost[i][j];

	return dp[m][n];
}

int main()
{
   freopen("in.in", "r", stdin);
   freopen("out.out", "w", stdout);
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << minCost(cost, 2, 2);
   return 0;
}