#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > v)
{
	int n = v.size();
	int m = v[0].size();

	int grid[n+1][m+1], sum[n+1][m+1], A[n+1][m+1];
	memset(grid, 0, sizeof(grid));
	memset(sum, 0, sizeof(sum));
	memset(A, 0, sizeof(A));

	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			grid[i+1][j+1] = v[i][j];

	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			sum[i][j] = grid[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
		{
			if(grid[i][j] == 0)
			{
				A[i][j] = 0;
				continue;
			}
			A[i][j] = A[i-1][j-1] + 1;

			int i1, j1, submatrix_sum, submatrix_size;
			while(A[i][j] > 0)
			{
				i1 = i - A[i][j] + 1;
				j1 = j - A[i][j] + 1;

				submatrix_sum = sum[i][j] - sum[i1-1][j] - sum[i][j1-1] + sum[i1-1][j1-1];
				submatrix_size = (A[i][j])*(A[i][j]);

				if(submatrix_size == submatrix_sum)
					break;

				A[i][j]--;
			}
		}

	int ans = 0; 
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			ans = max(ans, A[i][j]);

	return ans;
}

int main()
{

}