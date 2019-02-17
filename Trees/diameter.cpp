#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int deepestLeaf[N], ans[N];

void dfs(int u, int p)// p-->parent
{
	int neigh;
	bool leaf = true;

	deepestLeaf[u] = ans = 0;//for every node, the farthest distance of any leaf from it

	vector<int> v;
	v.clear();
	for(int i = 0; i < adj[u].size(); i++)
	{
		neigh = adj[u][i];
		if(neigh != p)
		{
			dfs(neigh, u);

			leaf = false;

			deepestLeaf[u] = max(deepestLeaf[u], deepestLeaf[neigh] + 1);
			v.push_back(deepestLeaf[neigh] + 1);
		}
	}

	ans = deepestLeaf[u];

	sort(v.begin(), v.end(), greater<int>());
	if(v.size() > 1)
		ans = max(ans, v[0] + v[1]);

	return;
}

int main()
{
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    int n, a, b;
    cin >> n;
    for(int i = 1; i<n; i++)
    {
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    dfs(1, 0);

    int final_ans = 0;
    for(int i = 1; i<=n; i++)
    	final_ans = max(final_ans, ans[i]);

    cout << final_ans << "\n";

    return 0;
}