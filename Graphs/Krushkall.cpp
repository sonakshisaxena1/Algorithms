//O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef pair <int, int> pii;
pair<int, pii> edges[N];
vector<pii> adj[N];
int size[N], parent[N];
int V, E;
void intialise()
{
    memset(size, 1, N + 1);
    for(int i = 1; i <= V; i++)
        parent[i] = i;
}

int find(int u)
{
    int root  = u;
    while(parent[root] != root)
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

bool isConnected(int x, int y)
{
    return (find(x) == find(y));
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    cin >> V >> E;
    intialise();
    int sum = 0;
    for(int i = 1; i <= E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].first = w;
        edges[i].second.first = a;
        edges[i].second.second = b;
       
    }

    sort(edges + 1, edges + 1 + E);
    for(int i = 1; i <= E; i++)
    {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;
        if(isConnected(a, b) == false)
        {
            sum += w;
            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
            merge(a,b);
        }
    }
    cout << sum;
    return 0;
}