//Maximum Bipartite Matching Problem
#include<bits/stdc++.h>
using namespace std;
#define M 6
#define N 6

bool bpm(bool G[M][N], int u, bool seen[], int match[] )
{
	for (int v =0 ; v < N; v++)
	{
		if(G[u][v] && seen[v] != true)
		{
			seen[v] = true;
			if(match[v] < 0 || bpm(G, match[v], seen, match))
			{
				match[v] = u;
				return true;
			}
		}

	}
	return false;

}

int maxBPM(bool G[M][N])
{
	int match[N]; //keeps track of the applicant assigned to the ith job
	memset(match, -1, sizeof(match));

	int result = 0;
	for(int u = 0; u < M; u++)
	{
		bool seen[N]; 
		memset(seen, 0, N); //marks all jobs unseen by the applicant
		
		if(bpm(G, u, seen, match)) //if applicant u can get a job
			result++;

	}

	return result;


}


int main()
{
    freopen("out.out", "w", stdout);
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1}};
 
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);
 
    return 0;
}
