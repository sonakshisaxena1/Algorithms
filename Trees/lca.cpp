//Lowest Common Ancestor (O(n))
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[205];
int nodes, edges;
bool visited[205];
int parent[205];
int l[205];

void dfs(int u, int level)
{
    visited[u] = true;
    l[u] = level;
    for(int i =0; i < adj[u].size(); i++)
    {
        int neigh = adj[u][i];
        if(!visited[neigh])
        {
            parent[neigh] = u;
            dfs(neigh, level + 1);
        }
    }

}

int lca(int a, int b)
{

    while(l[a] < l[b])
    {
        b = parent[b];
    }
    while(l[a] > l[b])
    {
        a = parent[a];
    }

    while(a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    
    cin >> nodes >> edges;
    int a, b;
    for(int i = 0; i < edges; i++)
    {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> a >> b;
    parent[0] = 0;
    dfs(0, 0);
    cout << lca(a, b);
    return 0;

}