#include<bits/stdc++.h>
using namespace std;
vector<int> price;
vector<int> backtrack(int s[][], int n)
{
    int x = n;
    int y = n;
    vector<int> result;
    result.clear();
    while(x != 0 || y != 0)
    {
        if(s[x][y] == -1)
        {
            x--;
            continue;
        }
       result.push_back(x);
        y -= x;
    }
    sort(result.begin(), result.end());
    return result ;
}

int cuttingRod()
{
    int n = price.size();
    int dp[n + 1][n + 1];
    int s[n+1][n+1];
    //-1 --> dp{i-1,j}
    //
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            s[i][j] = -1;
            if(j >= i){
                if(dp[i][j] < dp[i][j-i] + price[i-1]) {
                    dp[i][j] = dp[i][j-i] + price[i-1];
                    s[i][j] = 1;
                }
            }
        }

    backtrack(s, n);
  
    return dp[n][n];
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        int x;
        cin >> x;
        price.push_back(x);
    }

    vector<int> r = cuttingRod();
    for(int i = 0; i < r.size(); i++)
        cout << r[i] << " ";
    return 0;

}