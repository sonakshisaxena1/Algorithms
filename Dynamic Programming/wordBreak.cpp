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
void powerP()
{
    arr[0] = 1;
    for(int i = 1; i < 1000000; i++)
        arr[i] = (arr[i-1] * p) % mod; 
}
void hashTable()
{
    for(int i = 0 ; i < dict.size(); i++)
    {
        ll h = 0;
        string t = dict[i];
        for(int j = 0; j < t.size(); j++)
        {
            h = (h + ((ll)(t[j] - 'a' + 1LL) * arr[j])) % mod;
        } 
        s.insert(h);
    }

   
}
bool wordbreak(string str)
{
    powerP();
    hashTable();
    int n = str.length();
    bool dp[n+1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i = 1; i <= n; i++)
    {
        ll h = 0;
        for(int j = i; j > 0; j--)
        {
            h = (h*p + (ll)(str[j-1]-'a'+1LL)) % mod;
            if(s.find(h) != s.end())
                dp[i] |= dp[j-1];
            cout << dp[i] << " " << j << "\n";
            if(dp[i])
                break;
        }
    }
    return dp[n];
}
int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int k;
    cin >> k;
    for(int i = 0; i < k ; i++)
    {
        string s;
        cin >> s;
        dict.push_back(s);
    }
    string t;
    cin >> t;
    if(wordbreak(t))
        cout << "Yes";
    else
        cout << "no";
    return 0;
    
}