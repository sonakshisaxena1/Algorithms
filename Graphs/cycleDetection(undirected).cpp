#include<bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool visited[105];
int parent[105];
int V, E;


void dfs(int s)
{
    visited[s] = true;

    for(int i = 0; i < adj[s].size(); i++)
    {

        int neigh = adj[s][i];
        if(parent[s] != neigh)
        {
            if(visited[neigh])
            {
            	cout << neigh << " " << s << " ";
                int temp = parent[s];
                while(temp != neigh)
                {
                    cout << temp << " ";
                    temp = parent[temp];
                }
                exit(0);
            }
        
	        else
	        {
	            parent[neigh] = s;
	            dfs(neigh);
	        }
        }
    }
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
        adj[b].push_back(a);
    }
    parent[1] = 1;
    dfs(1);
    return 0;
}