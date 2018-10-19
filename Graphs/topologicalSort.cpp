//postorder traversal of DAG
//postorder in modified dfs gives topological
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool visited[105];
stack<int> s;

int V, E;
// int degree[105];
void topologicalSort(int u)
{
    visited[u] = true;
    for(int i = 0;i < adj[u].size(); i++)
    {
        int neigh = adj[u][i];
        if(!visited[neigh])
        {
            topologicalSort(neigh);
        }
    }
    s.push(u);

}
int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    cin >> V >> E;

    for(int i =0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++;
    }
    // int src;
    // for(int i = 1; i <= V; i++)
    //     if(degree[i] == 0)
    //         src = i;

    topologicalSort(1);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
    
}