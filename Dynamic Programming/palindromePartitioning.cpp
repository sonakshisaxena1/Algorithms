#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;
typedef pair<string, int> psi;
vector<int> adj[200000];
vector<int> adj1[200000];
int V, E;
vector<string> dict; 
set <ll> s;
ll p = 31;
ll  mod = 10000000007;
ll arr[1000000];
ll inv_arr[1000000];
ll modularExp(ll a, ll b)
{
    ll result = 1;
    a %= mod;
    while(b > 0)
    {
        if(b&1)
            result = (result * a) % mod;
        b >>= 1;
        a = (a*a) % mod;
    }
    return result;
}
void powerP()
{
    arr[0] = 1; 
    inv_arr[0] = 1;
    inv_arr[1] = modularExp(p, mod-2);
    for(int i = 2; i < 1000000; i++)
    {
        inv_arr[i] = (inv_arr[i-1] * inv_arr[1]) % mod;
     }

    for(int i = 1; i < 1000000; i++)
        arr[i] = (arr[i-1] * p) % mod; 

}



int palindromepartitioning(string str)
{
    powerP();
    int n = str.length();
    int dp[n+1];
    memset(dp, mod, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        ll h1 = 0;
        ll h2 = 0;
        for(int j = i; j > 0; j--)
        {
            h1 = (h1*p + (ll)(str[j-1]-'a'+1LL)) % mod;
            h2 = (h2 + (ll)(str[j-1]-'a'+1LL) * arr[i-j]) % mod;

            if(h1 == h2)
                dp[i] = min(dp[i], dp[j-1] + 1 );
           
        }
    }
    return dp[n] - 1;
}
int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    string t;
    cin >> t;
    cout << palindromepartitioning(t);
    return 0;
    
}