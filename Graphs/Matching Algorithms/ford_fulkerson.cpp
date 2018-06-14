
//time complexity: O(max flow* E)

#include<bits/stdc++.h>
using namespace std;
#define V 6


bool bfs(int residual[V][V], int s, int t, int parent[])
{
	queue<int> q;
	bool visited[V];
	memset(visited, false, V);
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(int v = 0 ; v < V; v++)
		{
			if(visited[v] == false && residual[front][v] > 0 )
			{
				visited[v] = true;
				parent[v] = front;
				q.push(v);

			}
		}
	}

	return(visited[t] == true);

}

int fordFulkerson(int G[V][V], int s, int t)
{
	int u, v;
	int residual[V][V];
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			residual[i][j] = G[i][j];

	int parent[V];
	int max_flow = 0;

	while(bfs(residual, s, t, parent) == true )
	{
		int path_flow = INT_MAX;
		for( v = t; v != s; v = parent[v])
		{
			u = parent[v];
			path_flow = min(residual[u][v], path_flow);

		}

		for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow = path_flow;
	}

	return max_flow;
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
 
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
 
    return 0;
}