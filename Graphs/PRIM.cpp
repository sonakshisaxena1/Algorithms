/******************** PRIM's Algorithm ***************/

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

Number of Vertices - 5
Number of Edges - 7

Edges are of the form - <Node 1> <Node 2> <Weight of the Edge>
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int N = 100005;
vector< pii > adjacency[N];
vector< pii > MST[N];

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

	int init = 1;

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
		int weight = tp.first;

		if(visited[ver])
			continue;

		visited[ver] = true;
		MST[ver].push_back(make_pair(par, weight));
		MST[par].push_back(make_pair(ver, weight));

		for(int i = 0; i<adjacency[ver].size(); i++)
		{
			pii neigh = adjacency[ver][i];

			if(visited[neigh.first])
				continue;

			pq.push(make_pair(neigh.second, make_pair(neigh.first, ver)));
		}
	}

	cout << "MST ->\n\n";
	for(int i = 1; i<=V; i++)
	{
		cout << "Node " << i << "\n";

		cout << "Neighbours -> ";
		for(int j = 0; j<MST[i].size(); j++)
			cout << MST[i][j].first << " ";

		cout << "\n\n";
	}

	return 0;
}