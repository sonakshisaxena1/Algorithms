#include <bits/stdc++.h>
using namespace std;
 
const int N = 1003;
int grid[N][N], prefix_col[N][N], A[N];
unordered_map<int, int> M;
 
int solve1(int row1, int row2, int n)
{
	for(int i = 1; i<=n; i++)
		A[i] = prefix_col[row2][i] - prefix_col[row1 - 1][i];
 
	M.clear();
	int prefix = 0;
	M[0] = 1;
 
	int ans = 0;
 
	for(int i = 1; i<=n; i++)
	{
		prefix += A[i];
		ans += M[prefix];
		M[prefix]++;
	}
 
	return ans;
}
 
void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			cin >> grid[i][j];
	for(int j = 1; j<=n; j++)
		for(int i = 1; i<=n; i++)
			prefix_col[i][j] = prefix_col[i-1][j] + grid[i][j];
 
	int ans = 0;
	for(int row1 = 1; row1 <= n; row1++)
		for(int row2 = row1; row2 <= n; row2++)
			ans += solve1(row1, row2, n);
 
	cout << ans << "\n";
 
	return;
}
 
int main()
{	
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
 
	solve();
 
	return 0;
}