#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<string, int> psi;

bool interleaved(string a, string b, string c)
{
    int m = a.length();
    int n = b.length();
    int p = c.length();
    if(p != m+n)
        return false;
    bool dp[m+1][n+1];
    memset(dp, false, sizepf(dp));
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 && j == 0)
                dp[0][0] = true;
            else if(i == 0 && (b[j] == c[j])){
                    dp[i][j] = dp[i][j-1];
            }
            else if(j == 0 && (a[i] == c[i])){
                    dp[i][j] = dp[i-1][j];
            }
            else if((a[i-1] == c[i+j-1]) && (b[j-1]!= c[i+j-1]))
                dp[i][j] = dp[i-1][j];
            else if((b[j-1] == c[i+j-1]) && (a[i-1] != c[i+j-1]))
                dp[i][j] = dp[i][j-1];
            else if((a[i-1] == c[i+j-1]) && (a[i-1] == b[j-1]))
                dp[i][j] = dp[i][j-1] || dp[i-1][j];

        }

    return dp[m][n];
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    string a, b, c;
    cin >> a >> b >> c;
    if(interleaved(a, b, c))
        cout << " yes";
    else
        cout << " No";
    return 0;
    
}