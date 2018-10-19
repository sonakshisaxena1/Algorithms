//Max subarray sum
#include <bits/stdc++.h>
using namespace std;
vector<int>A;

int solve()
{   
    int n = A.size();
    int dp[n], prefixSum[n], minprefixSum[n];
    prefixSum[0] = A[0];
    minprefixSum[0] = min(0, A[0]); //if empty is included too otherwise A[0]
    dp[0] = max(A[0], 0);
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + A[i];
        minprefixSum[i] = min(minprefixSum[i-1], prefixSum[i]);
        dp[i] = max(dp[i-1], prefixSum[i] - minprefixSum[i-1] ); 
    }
    return dp[n-1];
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << solve();

    return 0;

}