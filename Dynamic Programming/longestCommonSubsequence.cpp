#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b)
{
	if(b.length() == 0 || a.length() == 0)
		return 0;
	int D[a.length() + 1][b.length() + 1];
	for(int i = 0; i <= a.length(); i++)
	{
		for(int j = 0; j <= b.length(); j++)
		{
			if(i == 0 || j == 0)
					D[i][j] = 0;
			else if(a[i-1] == b[j-1])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);

		}
	}
	return D[a.length()][b.length()];
}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	cout << longestCommonSubsequence(a, b);
	return 0;
}