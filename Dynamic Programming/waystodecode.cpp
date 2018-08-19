#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    string A;
    cin >> A;
    dp[0] = 1;
    for(int i = 0; i < A.size(); i++)
    {
        dp[i+1] = 0;
        if(A[i] != '0')
             dp[i+1] += dp[i];
    
        if(i > 0 && A[i-1] != '0')
        {
            int ans = 0;
            ans += (A[i-1] - '0')*10 + (A[i] - '0');
            if(ans >0 && ans < 27)
                dp[i+1] += dp[i - 1];

        }
    }

    

    cout << dp[A.size()];

    
    
    return 0;
}