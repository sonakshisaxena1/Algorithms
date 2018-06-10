#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int V, E;
vector < int > adj[N];
stack <int> s;
bool visited[N];

void topological(int source)
{
	
	visited[source] = true;
	for(int i = 0; i < adj[source].size(); i++)
		if(visited[adj[source][i]] == false)
			topological(adj[source][i]);

	s.push(source);

}
void dfs()
{
	
	for (int i = 0; i < V; i++)
        visited[i] = false;

	for(int i = 0; i < V; i++)
	{
		if(visited[i] == false)
			topological(i);

	}

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

}


int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int a, b;
	cin >> V >> E;

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}

	dfs();
	return 0;

}