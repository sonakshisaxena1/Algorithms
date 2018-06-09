//Time Complexity: O(V^3)

#include<bits/stdc++.h>
using namespace;

const int N = 105;
int dp[N][N];
vector< pair <int, int> > adj[N];

int main()
{
	int V, E, a, b, w;
	cin >> V >> E;


	for(int i = 0; i< V; i++)
		for(int j = 0; j < V; j++)
		{
			if(i == j)
				dp[i][j] = 0;
			
			else

				dp[i][j] = INT_MAX;
		}

	for(int i = 0; i < E; i++)
		{
			cin >> a >> b >> w;
			dp[a][b] = min(dp[a][b], w);
			dp[b][a] = min(dp[b][a], w);
			
		}

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++ )
			for(int k = 0; k < V; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	for(int i = 0; i< V; i++)
	    {
	        for(int j = 0; j < V; j++)
	        {
	            cout << dp[i][j] << " ";
	        }
	        cout << "\n";
	    }

	return 0;
}