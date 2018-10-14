#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector< vector<int> > A;
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int t;
    cin >> t;
    while(t > 0)
    {
        ll x, y;
        cin >> x >> y;
        if((ll)(x*0.75) <= y)
        {
            cout << 0 <<"\n";
            continue;
        }
        ll res = 3*x - 4*y;
        cout << res << "\n";
        t--;
    }
    return 0;
}