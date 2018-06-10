#include <bits/stdc++.h>
using namespace std;
//Krushkal
const int N = 104;//array size->N
int id[N], sz[N];

vector< pair<int, int> > adj[N];

pair< int, pair<int, int> > Edges[N];

void init(int V)
{
    for(int i = 1; i<=V; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    return;
}

int root(int a)
{
    int fin = a;
    while(id[fin] != fin)
        fin = id[fin];
    int temp;
    while(id[u] != u)
    {
        temp = id[u];
        id[u] = temp;
        u = temp;
    }
    return fin;
}

void merge(int a, int b)
{
    a = root(a);
    b = root(b);
    
    if(sz[a] < sz[b])
    {
        id[a] = b;
        sz[b] += sz[a];
        
        return;
    }
    
    id[b] = a;
    sz[a] += sz[b];
    
    return;
}

bool isConnected(int a, int b)
{
    return (root(a) == root(b));
}

int main()
{
    int V, E, a, b, w, sum = 0;
    cin >> V >> E;
    
    for(int i = 1; i<=E; i++)
    {
        cin >> a >> b >> w;
        
        Edges[i].first = w;
        Edges[i].second.first = a;
        Edges[i].second.second = b;
    }
    
    sort(Edges + 1, Edges + 1 + E);
    
    for(int i = 1; i<=E; i++)
    {
        a = Edges[i].second.first;
        b = Edges[i].second.second;
        
        if(isConnected(a, b) == false)
        {
            sum += w;
            
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
            
            merge(a, b);
        }
    }
    
    
    
    return 0;
}