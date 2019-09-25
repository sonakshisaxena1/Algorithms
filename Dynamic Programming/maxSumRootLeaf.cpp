//maximum node to leaf sum using tree dp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>adj[100007];
bool visited[100007];
ll dp[100007];
ll sumdp[100007];
ll val[100007];
ll X, N;
void dfs(int node)
{
    visited[node] = true;
    sumdp[node] = val[node];
    for(int i = 0; i < adj[node].size(); i++)
    {
        int neigh = adj[node][i];
        if(!visited[neigh])
        {
            dfs(neigh);
            sumdp[node] = max(sumdp[node], val[node]+sumdp[neigh]);
        }
    }
}

int main()
 {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
   
       
        cin >> N;
        adj[N].clear();
        for(int i = 1; i <= N; i++)
        {
            sumdp[i] = 0;
            visited[i] = false;
            adj[i].clear();

        }
        for(int i = 1; i <= N; i++)
            cin >> val[i];
      
        for(int i = 1; i <= 12; i++)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1);
       
        cout << sumdp[1] << "\n";

    return 0;
}


