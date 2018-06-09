#include<bits/stdc++.h>
using namespace std;


//Recursive Solution
/*int eggRecur(int n, int k) // n--> eggs k --> floors
{
	if(k == 0 || k == 1)
		return k;

	if(n == 1)
		return k;

	int min = INT_MAX;
	for(int x = 1 ; x <= k; x++)
		{
			int res = (max(eggRecur(n-1,x-1), eggRecur(n, k-x)));
			if(res < min)
				min = res;
		}

	return 1 + min;

} */

//Dynamic Programming 
//Time complexity : O(n * (k^2))
//Space complexity: O(n*k)

int eggDrop(int n, int k)
{
	int dp[n+1][k+1];
	int res;

	for(int i = 1; i <=n; i++)
		{
			dp[i][0] = 0;
			dp[i][1] = 1;
		}

	for(int i = 1 ; i <= k ; i++)
		dp[1][i] = i;

	for(int i = 2; i <= n ; i++)
		for(int j = 2; j <= k; j++)
			{
				dp[i][j] = INT_MAX;
				for(int x = 1; x <= j; x++)
				{
					res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
					if(res < dp[i][j])
						dp[i][j] = res;
				}
			}

	return dp[n][k];

}

int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n = 2, k = 36;
    //cout << "Minimum number of trials (using recursion): " << eggRecur(n, k)<<endl;
    

    cout << "Minimum number of trials (using dp): " << eggDrop(n, k);
    return 0;
}

