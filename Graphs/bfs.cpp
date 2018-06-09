//Time Complexity : O(V+E)


#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int>adj[N];
bool visited[N];

void bfs(int root)
{
	memset(visited, false, N);
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		visited[v] = true;
		for(int i = 0; i<adj[v].size(); i++)
		{
			int neigh = adj[v][i];
			if(visited[neigh] == false)
				{
					q.push(neigh);
					visited[neigh] = true;
				}
			else
				continue;
		}

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

	bfs(2);
	return 0;
}