//Length of longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;
vector<int>A;
#define INF 1000007
int solve() {
    
    int n  = A.size();
    if(n == 0)
        return 0;
    int dp[n];
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if((i >= j) && A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }

    int ans = 1;
    for(int i = 0; i < n; i++)
       ans = max(ans, dp[i]);

    return ans;
    
}


int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
   
    cout << solve();
    return 0;
}