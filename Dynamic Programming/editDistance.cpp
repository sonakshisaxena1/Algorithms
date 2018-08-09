#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(string A, string B)
{
    int m = A.size();
    int n = B.size();
    if(n == 0)
        return m;
    if(m == 0)
        return -1;
    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++)
        for(int j = 0; j < n+1; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
        }

    return dp[m][n];

}
int main()
{
	ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    string A, B;
    cin >> A >> B;
    cout << editDistance(A, B);
	
	
	return 0;
}