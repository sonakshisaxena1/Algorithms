#include <bits/stdc++.h>
using namespace std;
const int N = 105;
#define INF 100000005;
const int R = 3;
const int C = 3;


int minCost(int A[R][C], int m, int n)
{
    int dp[R][C];
    dp[0][0] = A[0][0];
    for(int i = 1; i < C; i++)
        dp[0][i] = A[0][i] + dp[0][i-1];
    for(int i = 1; i < R; i++)
        dp[i][0] = A[i][0] + dp[i-1][0];
    for(int i = 1; i < R; i++)
        for(int j = 1; j < C; j++)
            dp[i][j] = A[i][j] + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
    return dp[m][n];
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << minCost(cost,2,2);
 
    return 0;
}