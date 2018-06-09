//Time Complexity : O(V+E)
//V --> while loop and E --> for loop

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector < int > adj[N];
bool visited[N];

void dfs(int source)
{
	memset(visited, false, N);
	stack < int > s;
	s.push(source);

	while(!s.empty())
	{
		int front = s.top();
		visited[front] = true;
		cout << front << " ";
		s.pop();

		for(int i = 0; i < adj[front].size(); i++)
		{
			int neigh = adj[front][i];
			if(visited[neigh] == true)
				continue;

			s.push(neigh);
			visited[neigh] = true;
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

	dfs(2);
	return 0;

}