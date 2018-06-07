//Coverting str1 to str2 

#include<bits/stdc++.h>
using namespace std;


int editDistDP(string str1, string str2, int m, int n)
{
	int dp[m+1][n+1];

	for(int i = 0;i <=m; i++)
		for(int j = 0; j <=n; j++)
			{
				if(i==0)
					dp[i][j] = j;

				else if( j == 0)
					dp[i][j] = i;

				else if(str1[i-1] == str2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min ( min(dp[i-1][j], dp[i][j-1]),
								     dp[i-1][j-1] ) + 1;

			}

	return dp[m][n];
}
int main()
{ 	
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout); 
	string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistDP(str1, str2, str1.length(), str2.length());
 
    return 0;

}