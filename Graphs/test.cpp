//O(V+E)

#include<iostream>
#include<queue>
using namespace std;
const int N = 105;
vector<int>adj[N];
bool visited[N];

void bfs(int s)
{
    memset(visited, false, sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int tp = q.front();
        //visited[tp] = true;
        q.pop();
        cout << tp << " ";
        for(int i = 0; i < adj[tp].size(); i++)
        {
            int neigh = adj[tp][i];
            if(!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(2);
    return 0;
}