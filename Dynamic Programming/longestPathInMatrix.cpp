//Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.
#include<bits/stdc++.h>
using namespace std;
#define n 3
int a[n][n];

int longestPathFromCell(int i, int j, int dp[n][n])
{
	if(i < 0 || i >= n || j < 0 || j >=n )
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	if((j < n-1) && ((a[i][j] + 1) == a[i][j+1] ))
		return (dp[i][j] = 1 + longestPathFromCell(i, j+1,dp));
	if((i < n-1) && ((a[i][j] + 1) == a[i+1][j] ))
		return (dp[i][j] =  1 + longestPathFromCell(i+1, j, dp));
	if((j > 0) && ((a[i][j] + 1) == a[i][j-1] ))
		return (dp[i][j] =  1 + longestPathFromCell(i, j-1, dp));
	if((i > 0) && ((a[i][j] + 1) == a[i-1][j] ))
		return (dp[i][j] =  1 + longestPathFromCell(i-1, j, dp));

	return (dp[i][j] = 1);


}
int longestPath()
{
	int dp[n][n];
	int result = 1;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] == -1)
				longestPathFromCell(i, j, dp);
			result = max(dp[i][j], result);
			cout << result << endl;

		}
	}

	return result;

}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int a[n][n] = {{1, 2, 9}, 
                    {5, 3, 8}, 
                    {4, 6, 7}};
	cout << longestPath();
	return 0;
	
}