#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef pair<string, int> psi;
vector<int> adj[200000];
vector<int> adj1[200000];
int V, E;
bool visited[200000];

void clone(int s)
{
    queue<int> q;
    q.push_back(s);
    visited[s] = true;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        for(int i = 0; i < adj[tp].size(); i++)
        {
            int neigh = adj[tp][i];
            if(visited[neigh] != true)
            {
                visited[neigh] = true;
                q.push_back(neigh);
                adj1[tp].push_back(neigh);
                adj1[neigh].push_back(tp);

            }
        }
    }

}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    clone(0);
    cout << "Cloned";
    
}