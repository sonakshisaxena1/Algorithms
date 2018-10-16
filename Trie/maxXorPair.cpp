//Max Xor between any two elements in an array
#include<bits/stdc++.h>
using namespace std;
int adj[205][2];
int node_cnt = 1;
vector<int> A;
int x;
string s;

void insert(int node, int index)
{
    if(s.size() == index)
        return;
    int c;
    if(s[index] == '0')
        c = 0;
    else
        c = 1;
        
    if(adj[node][c] == 0)
    {
        adj[node][c] = node_cnt;
        node_cnt++;
    }
    insert(adj[node][c], index + 1);
}

int maxXOR(int node1, int node2, int level)
{
    int ans = 0;
    if(adj[node1][0] != 0 && adj[node2][1] != 0 && level > -1)
        ans = max(ans, (1 << (level)) + maxXOR(adj[node1][0], adj[node2][1], level-1));
    if(adj[node1][1] != 0 && adj[node2][0] != 0 && level > -1)
        ans = max(ans, (1 << (level)) + maxXOR(adj[node1][1], adj[node2][0], level-1));
   
    if(ans != 0)
        return ans;


    if(adj[node1][0]== 0 && adj[node2][0] == 0 && level > -1)
        ans = max(ans, maxXOR(adj[node1][1], adj[node2][1], level-1));
    if(adj[node1][1]== 0 && adj[node2][1] == 0 && level > -1)
        ans = max(ans, maxXOR(adj[node1][0], adj[node2][0], level-1));
    return ans;
}

void solve()
{
    for(int i = 0; i < A.size(); i++)
    {
        int temp = A[i];
        s = "";
        while(temp > 0)
        {
            s += to_string(temp%2);
            temp/=2;
        }
        reverse(s.begin(), s.end());
        while(s.size() <= 9)
            s = "0" + s;
        
        insert(0,0);
    }

     cout << maxXOR(0,0, 9);
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        A.push_back(x);
    }

    solve();
    return 0;

}