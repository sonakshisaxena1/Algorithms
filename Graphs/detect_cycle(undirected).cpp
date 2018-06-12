#include<bits/stdc++.h>
using namespace std;
#define N 105

int size[N], parent[N];
void initialise(int V)
{
	
	for(int i = 0; i < V; i++)
	{
		size[i] = 1;
		parent[i] = i;
	}

}

int find(int u)
{
	int root = u;
	while(parent[root]!= root)
	{
		parent[root] = parent[parent[root]];
		root = parent[root];
	}

	return root;
}

void merge(int x, int y)
{
	int root_x = parent[x];
	int root_y = parent[y];

	if(size[root_x] < size[root_y])
	{
		parent[root_x] = root_y;
		size[root_y] += size[root_x];
	}

	else
	{
		parent[root_y] = root_x;
		size[root_x] += size[root_y];
	}
}

int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

	int V, E, a, b;
	cin >> V >> E;

	initialise(V);

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		if(find(a) == find(b))
		{
			cout << "Cycle found";
			return 0;
		}
		else
		{
			merge(a, b);
		}
	}

	cout << "Cycle not found";

	return 0;



}