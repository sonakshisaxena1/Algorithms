//O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define N 105
int V, E;

int size[N];
int parent[N];

void initialise()
{
    memset(size, 1, N);
    for(int i = 1; i <= V; i++)
        parent[i] = i;

}
int find(int u) //-> Path compression (Olog*n)
{
    int root = u;
    while(parent[root] != root)
    {
        parent[root] = parent[parent[root]];
        root = parent[root];
    }
    return root;
}
void merge(int x, int y) // -> union by rank (Ologn)
{
    int root_x = parent[x];
    int root_y = parent[y];
    if(size[root_y] < size[root_x])
    {
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }
    else
    {
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
    }
}
int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    cin >> V >> E;
    for(int i = 1; i <= E; i++)
    {
        int a, b;
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