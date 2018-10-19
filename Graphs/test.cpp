
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[205];
int nodes, edges;
bool visited[205];
vector<int> v;
int parent[205];
void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int neigh = adj[u][i];
        if(parent[u] != neigh)
        {
            if(visited[neigh])
            {
                cout << neigh << " " << u << " ";
                int temp = parent[u];
                while(temp != neigh)
                {
                    cout << temp << " ";
                    temp = parent[temp];
                }
                exit(0);
            }
            else
            {   
                parent[neigh] = u;
                dfs(neigh);
            }
                
        }
    }

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
        adj[b].push_back(a);
    }
    

    dfs(1);
    
    return 0;

}