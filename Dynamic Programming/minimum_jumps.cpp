#include <bits/stdc++.h>
using namespace std;
const int N = 105;
#define INF 100000005;

vector<int> A;

int minjumpArray()
{
    int dp[A.size()];
    if(A.size() == 0)
        return -1;
    if(A.size() == 1)
        return 0;
    dp[0] = 0;
    for(int i = 1; i < A.size(); i++)
    {
        dp[i] = INT_MAX;
        for(int j = 0; j < i; j++)
        {
            if((i <= A[j] + j) && (dp[j] != INT_MAX))
            {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return dp[A.size() - 1];
  
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << minjumpArray();
    

    return 0;
}