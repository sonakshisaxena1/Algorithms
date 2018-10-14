#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< vector<int> > A;

int waysGrid()
{
    int m = A.size();
    int n = A[0].size();
    ll dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(A[i-1][j-1] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    return dp[m][n];
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("test.out", "w", stdout);
    string P, S;
    cin >> S >> P;
    cout << isRegular(S, P);
    return 0;

}