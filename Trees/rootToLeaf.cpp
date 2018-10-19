
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[205];
int nodes, edges;
bool visited[205];
vector<int> v;

void dfs(int u, int sum)
{
    visited[u] = true;
    sum = sum*10 + u;
    bool flag = false;
    
    for(int i = 0; i < adj[u].size(); i++)
    {
        int neigh = adj[u][i];
        if(!visited[neigh])
        {
            flag = true;
            dfs(neigh, sum);
        }
    }

    if(!flag)
    {
        v.push_back(sum);
        sum = 0;
    }

}

int roottoLeaf()
{
    int ans = 0;
    for(int i =0; i < v.size(); i++)
        ans = (ans + v[i]) % 1003;
    return ans;
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
    
    dfs(1, 0);
    cout << roottoLeaf();
    return 0;

}