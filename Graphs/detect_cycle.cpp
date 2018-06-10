#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int V, E;
vector < int > adj[N];
bool visited[N];
bool recStack[N];

bool isCyclicCheck(int v, bool visited[], bool recStack[])
{
	if(visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;

		for(int i = 0; i < adj[v].size(); i++)
		{
			if(visited[i] == false && isCyclicCheck(i, visited, recStack) == true)
				return true;

			else if(recStack[i] == true)
				return true;

		}
	}

	recStack[v] = false;
	return false;

}


bool isCyclic()
{
	memset(visited, false, N);
	memset(recStack, false, N);

	for(int i = 0; i < V; i++)
		if(isCyclicCheck(i, visited, recStack))
			return true;

	return false;

}

int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

	int  a, b;
	cin >> V >> E;

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);

	}

	if(isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;

}