#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N];
int main()
{
    ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    if(n == 0 || n == 1)
        cout << "1";
    else if (n == 2)
        cout << "2";
    else
    {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = 0;
            for(int k = 0; k < i; k++)
                dp[i] = (dp[i] + dp[k]*dp[i-k-1])%1000000007;
        }
        cout << dp[n]%1000000007;
    }

    

    return 0;
}