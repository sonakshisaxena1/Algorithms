//O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define INF 100005
typedef pair<int, int> pii;
const int N = 105;
vector<pair <int, int> >adj[N];
int V, E;

void dijkstra(int s)
{
    vector<int> dist(V, INF);
    
    priority_queue< pii , vector < pii >, greater <pii> > q;
    q.push(make_pair(0,s));
    dist[s] = 0;
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                q.push(make_pair(dist[v], v));
            }
            
        }
    }
    for(int i = 0; i < V; i++)
    {
        cout << "Vertex: "<< i << " Distance: " << dist[i] << "\n";
    }
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    dijkstra(0);
    return 0;
}