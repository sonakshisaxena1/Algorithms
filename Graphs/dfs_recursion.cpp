#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector < int > adj[N];
bool visited[N];

void dfs(int source)
{
	visited[source] = true;
	cout << source << " ";
	for(int i = 0 ; i < adj[source].size(); i++)
	{
		int neigh = adj[source][i];
		if(visited[neigh])
			continue;
		dfs(neigh);
	}

}


int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int V, E, a, b;
	cin >> V >> E;

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

	}

	dfs(2);
	return 0;

}