//Given a two strings S and T, find count of distinct occurrences of T in S as a subsequence.
#include<bits/stdc++.h>
using namespace std;
int distinctSubsequences(string T, string S)
{
    int m = T.size();
    int n = S.size();
    int dp[m+1][n+1];
    memset(dp, -1, sizeof(dp));
    for(int j = 0;j <= n; j++)
        dp[0][j] = 1;
    for(int i = 1; i <= m; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(T[i-1] != S[j-1])
                dp[i][j] = dp[i][j-1];
            else if(T[i-1] == S[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
        }

    return dp[m][n];
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    cout << distinctSubsequences(a, b);
    return 0;
    
}