//Sum of the elements of a sub matrix in a given matrix
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &v, int i1, int j1, int i2, int j2)
{
    int n = v.size();
    int m = v[0].size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1;i < n+1; i++)
        for(int j = 1; j < m+1; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + v[i-1][j-1];

    int ans = dp[i2+1][j2+1] - dp[i2+1][j1] - dp[i1][j2+1] + dp[i1][j1];
    return ans;
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n);
    for(int i = 0; i<n; i++)
    {
        v[i].resize(m);
        for(int j = 0; j<m; j++)
            cin >> v[i][j];
    }
    int i1, j1, i2, j2;
    cin >> i1>>j1>>i2>>j2;
    cout << solve(v, i1, j1, i2, j2) << "\n";

    return 0;

}