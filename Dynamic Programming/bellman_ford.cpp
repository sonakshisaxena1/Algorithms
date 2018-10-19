#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector< pair <int, int> > adjacency[N];

int main()
{
	int V, E, a, b, w;

	cin >> V >> E;
	for(int i = 1; i <= E; i++)
	{
		cin >> a >> b;
		adjacency[a].push_back(make_pair(b, w));
		adjacency[b].push_back(make_pair(a, w));

	}

	int dist[V+1];
	for(int i = 1 ; i <= V; i++)
		dist[i] = INT_MAX;

	dist[1] = 0;
	for(int i = 1; i<= V; i++)
		for(int j = 1; j<=V; j++)
			for(int k = 0; k<adjacency[j].size(); k++)
				dist[j] = min(dist[j], dist[adjacency[j][k].first] + adjacency[j][k].second);

	for(int i = 1; i<=V; i++)
		for(int j = 1; j<=V; j++)
			for(int k = 0; k<adjacency[j].size(); k++)
				if(dist[j] != dist[adjacency[j][k].first] + adjacency[j][k].second)
				{
					cout << "Contains negative cycle!";
					return 0;
				}

	cout << "Distance from Source\n";
	for(int i = 1; i<=V; i++)
		cout << dist[i] << " ";
	cout << "\n";

	return 0;


}