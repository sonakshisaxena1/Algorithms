#include<bits/stdc++.h>
using namespace std;
vector<int>wt;
vector<int>v;
int W;

int knapsack()
{
    int n = v.size();
    int dp[n+1][W+1];
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < W+1; j++)
        {
            if(i == 0 || j== 0)
                dp[i][j] = 0;
            else if (wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - wt[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }

    return dp[n][W];
}
int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n >> W;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        wt.push_back(a);
        v.push_back(b);
    }
    cout << knapsack();
    return 0;
}