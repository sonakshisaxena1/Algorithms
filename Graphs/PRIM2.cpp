#include<bits/stdc++.h>

using namespace std;
const int N = 105;
vector< pair< int, int> > adj[N];
bool visited[N];


void dijkstra(int root, int V, int E)
{

  priority_queue < pair <int, int>, vector < pair < int, int> >, greater <pair<int, int > > > q;
  q.push(make_pair(0, root));
  visited[root] = true;
  while(!q.empty())
  {
    pair<int, int> f = q.top();
    cout << f.second << endl;

    q.pop();
    
    for(int i = 0; i < adj[f.second].size(); i++)
    {

      int neigh = adj[f.second][i].first;
      if(visited[neigh] == true)
        continue;

      visited[neigh] = true;
      q.push(make_pair(adj[f.second][i].second, neigh));
      
    }
  }

}

int main()
{

  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int V, E, a, b, w;
  cin >> V >> E;
  for(int i = 1; i <= E; i++)
  {
    cin >> a >> b >> w;
    adj[a].push_back(make_pair(b, w));
    adj[b].push_back(make_pair(a, w));
  }

  dijkstra(1, V, E);


  return 0;
}