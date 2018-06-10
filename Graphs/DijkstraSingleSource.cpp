/**** Dijkstra Single Source Shortest Path Algorithm ****/

/*
Example Input - 
5 7
1 2 1
1 3 2
2 3 3
3 5 2
3 4 2
2 4 4
4 5 1
1

Number of Vertices - 5
Number of Edges - 7
The Single Source - 1
The last Integer in Input is the Single Source on which we want to run the algorithm

Edges are of the form - <Node 1> <Node 2> <Weight of the Edge>
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;

#define INF 1000000009

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int N = 100005;
vector< pii > adjacency[N];
vector< pii > shortestPath[N];

bool visited[N];

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int V, E;
	cin >> V >> E;

	int a, b, w;
	for(int i = 1; i<=E; i++)
	{
		cin >> a >> b >> w;

		adjacency[a].push_back(make_pair(b, w));
		adjacency[b].push_back(make_pair(a, w));
	}

	int init;

	cin >> init;

	visited[init] = true;

	priority_queue< pipii, vector<pipii>, greater<pipii> > pq;

	for(int i = 0; i<adjacency[init].size(); i++)
	{
		pii neigh = adjacency[init][i];
		pq.push(make_pair(neigh.second, make_pair(neigh.first, init)));
	}

	while(!pq.empty())
	{
		pipii tp = pq.top();

		pq.pop();

		int ver = tp.second.first;
		int par = tp.second.second;
		int dist = tp.first;

		if(visited[ver])
			continue;

		visited[ver] = true;
		shortestPath[ver].push_back(make_pair(par, dist));
		shortestPath[par].push_back(make_pair(ver, dist));

		for(int i = 0; i<adjacency[ver].size(); i++)
		{
			pii neigh = adjacency[ver][i];

			if(visited[neigh.first])
				continue;

			pq.push(make_pair(dist + neigh.second, make_pair(neigh.first, ver)));
		}
	}

	cout << "shortestPath Graph ->\n\n";
	for(int i = 1; i<=V; i++)
	{
		cout << "Node " << i << "\n";

		cout << "Neighbours -> ";
		for(int j = 0; j<shortestPath[i].size(); j++)
			cout << shortestPath[i][j].first << " ";

		cout << "\n\n";
	}

	return 0;
}