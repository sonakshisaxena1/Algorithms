#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<string, int> psi;
#define ll long long
vector<int> adj[200000];

ll modularExponentiation(ll x, ll y, ll p)
{
    ll result = 1;
    x %= p;

    while(y > 0)
    {
        if(y&1)
            result  = (result * x) % p;
        x = (x*x) % p;
        y >>= 1;
    }
    return result;
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while(t > 0)
    {
        ll a, b;
        cin >> a >> b;
        cout << modularExponentiation(a, b, 10) << "\n";
        t--;
    }
    return 0;
    
}