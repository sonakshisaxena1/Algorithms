//Base on max flow min cut theorem

#include<bits/stdc++.h>
using namespace std;
#define V 6

bool bfs(int residual[V][V], int s, int t, int parent[])
{
	bool visited[V];
	memset(visited, false, V);
	queue<int>q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < V; v++)
		{
			if(visited[v] == false && residual[u][v] > 0)
			{
				visited[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}

	return(visited[t] == true);

}

void dfs(int residual[V][V], int s, bool visited[])
{
	visited[s] = true;
	for(int v = 0; v < V; v++)
	{
		if(residual[s][v] > 0 && visited[v] == false)
			dfs(residual, v, visited);
	}
}

void minCut(int G[V][V], int s, int t)
{
	int u, v;
	int residual[V][V];
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			residual[i][j] = G[i][j];

	int parent[V];
	
	while(bfs(residual, s, t, parent))
	{
		int path_flow = INT_MAX;
		for( v = t; v != s; v = parent[v])
			{
				u = parent[v];
				path_flow = min(path_flow, residual[u][v]);
			}

		for(v = t; v != s; v = parent[v])
		{
			u = parent[v];
			residual[u][v] -= path_flow;
			residual[v][u] += path_flow;
		}

	}
	// Now we have the maximum flow and we need to find all reachable vertices from s

	bool visited[V];
	memset(visited, false, V);
	dfs(residual, s, visited);

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
		{
			if(visited[i] && !visited[j] && G[i][j])
				cout << i << " --> " << j << endl;
			

		}

	return;

}

int main()
{
	freopen("out.out", "w", stdout);
	int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
    
    minCut(graph, 0, 5);
 
    return 0;
}