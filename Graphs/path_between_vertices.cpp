//Find if there is a path between two vertices in a directed graph

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int>adj[N];
bool visited[N];

bool bfs(int root, int final)
{
	if(root == final)
		return true;

	memset(visited, false, N);
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		if(v == final)
			return true;
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
	return false;

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
	}

	int root, final;
	cin >> root >> final;

	if(bfs(root, final))
		cout<< "There is a path between "<<root << " and " << final ;
	else
		cout<< "There is no path between "<<root << " and " << final ;
	return 0;
	return 0;
}