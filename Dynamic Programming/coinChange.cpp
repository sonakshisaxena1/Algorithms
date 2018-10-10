#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<string, int> psi;
vector<int>S;

int coinChange(int m, int n)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m <= 0 && n >= 1)
        return 0;
    return coinChange(m-1, n) + coinChange(m, n - S[m-1]);
}

int coinChangeDp(int m, int n)
{
    int table[n+1][m];
    for (int i=0; i<m; i++) 
        table[0][i] = 1; 
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
        {
            int x, y;
            if(i - S[j] >= 0)
                x = table[i - S[j]][j];
            else
                x = 0;
            if(j >= 1)
                y = table[i][j-1];
            else
                y = 0;
            table[i][j] = x + y;
            
        }
    return table[n][m-1];
}
int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        S.push_back(x);
    }
    int n;
    cin >> n;

    cout << coinChange(m, n) << "\n";
    cout << coinChangeDp(m, n) << "\n";
    return 0;
    
}