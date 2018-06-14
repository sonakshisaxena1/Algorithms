//Finding shortest path from a single source in DAG in O(V+E)
// We can do that using dfs
//Using Dijkstra's the time complexity is: O(E + VlogV)
//Using Bellmann Ford's the time complexity is: O(VE)

#include<bits/stdc++.h>
using namespace std;
#define N 105
#define INF INT_MAX
int V;
bool visited[N];
vector < pair <int, int > > adj[N];
stack<int> s;

void dfs(int source)
{
	visited[source] = true;
	for(int i = 0; i < adj[source].size(); i++)
	{
		int neigh = adj[source][i].first;
		cout << neigh << endl;
		if(visited[neigh] == false)
		{
			dfs(neigh);
		}
	}

	s.push(source);
}

void shortestPath(int source)
{
	int dist[V];
	memset(dist, INF, V);
	dist[V] = 0;

	dfs(source);

	while(!s.empty())
	{
		int u = s.top();
		s.pop();

		if(dist[u] != INF)
		{
			for(int i = 0; i < adj[u].size(); i++){
				if(dist[i] > (dist[u]+ adj[u][i].second))
					dist[i] = dist[u]+ adj[u][i].second;


			//cout << "Hi";

			}
		}
	}

	for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}


int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int E, a, b, w;
	cin >> V >> E;
	for(int i = 0 ; i < E; i++)
	{
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b,w));
	}

	int s = 1;
    cout << "Following are shortest distances from source " << s <<" n";
    shortestPath(s);

    return 0;
 }