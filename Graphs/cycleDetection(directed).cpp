#include<bits/stdc++.h>
using namespace std;
vector<int>A;
vector<int>adj[105];
bool visited[105];
int parent[105];
bool recStack[105];
int V, E;
void dfs(int u)
{
    recStack[u] = true;
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int neigh = adj[u][i];
        if(!visited[neigh])
        {
            parent[neigh] = u;
            dfs(neigh);
        }
        else if (recStack[neigh])
        {
            cout << neigh << " " << u << " ";
            int temp = u;
            while(parent[temp] != neigh)
            {
                temp = parent[temp];
                cout << temp << " ";
                
            }
            exit(0);
        }
    }
    recStack[u] = false;

}

int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    cin >> V >> E;
    for(int i = 1; i <= E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    return 0;
    
}