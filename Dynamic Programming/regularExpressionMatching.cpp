#include<bits/stdc++.h>
using namespace std;

//Space Complexity: O(m*n)
int isRegular(string S, string P)
{
    int m = P.size();
    int n = S.size();
    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    int k = 0;
    while((k < m)  && P[k] == '*')
    {
        dp[k+1][0] = true;
        k++;
    }
    for(int i = 1; i < m+1; i++)
        for(int j = 1; j < n+1; j++)
        {
            
            //cout << k << "\n";
            if((P[i-1] == S[j-1]) || (P[i-1] == '?'))
                dp[i][j] = dp[i-1][j-1];
            else if(P[i-1] == '*')
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
        }

    for(int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    if(dp[m][n])
        return 1;
    return 0;
}

//Space Complexity O(2*m)

int isRegular1(string S, string P)
{
    int n = S.size();
    int m = P.size();
    bool dp[2][m+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 0; i<P.size(); i++)
    {
        if(P[i] != '*')
            break;
        dp[0][i+1] = true;
    }
    bool flag = true;
    for(int i = 1; i<=n; i++)
    {
        dp[flag][0] = false;
        if(P[0] == '*')
            dp[flag][0] = true;
        for(int j = 1; j<=m; j++)
        {
            dp[flag][j] = false;
            if(P[j-1] == '*')
                dp[flag][j] = dp[flag][j-1] | dp[!flag][j];
            else if(P[j-1] == '?')
                dp[flag][j] = dp[!flag][j-1];
            else
                dp[flag][j] = dp[!flag][j-1] & (S[i-1] == P[j-1]);
        }
        flag = !flag;
    }
 
    flag = !flag;
    if(dp[flag][m])
        return 1;
    return 0;
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