#include <bits/stdc++.h>
using namespace std;

const int N = 104;
int id[N], sz[N], comp;

void init(int V)
{
    for(int i = 1; i<=V; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    comp = V;
    
    return;
}

int find_id(int u) // Path Compression // O(log*V)
{
    int fin = u;
    
    while(id[fin] != fin)
    {
        fin = id[fin];
    }
    
    int parent;
    while(id[u] != fin) 
    {
        parent = id[u];
        id[u] = fin;   
        u = parent;
    }
    
    return fin;
}

void merge(int a, int b) // O(logV)
{
    a = find_id(a);
    b = find_id(b);
    
    comp--;
    
    if(sz[b] < sz[a]) 
    {
        id[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        id[a] = b;
        sz[b] += sz[a];
    }
    
    return;
}
 
bool isConnected(int a, int b) // O(logV)
{
    return (find_id(a) == find_id(b));
}

int main()
{
    int V, E, a, b;
    cin >> V >> E;
    
    init(V);
    
    for(int i = 1; i<=E; i++)
    {
        cin >> a >> b;
        
        if(isConnected(a, b) == false)
            merge(a, b);
    }
    
    
    
    cout << comp << "\n";
    
    return 0;
}