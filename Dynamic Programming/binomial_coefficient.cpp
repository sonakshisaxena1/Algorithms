//Time Complexity: O(n*k)
//Space Complexity: O(n*k)

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
	int dp[n+1][k+1];


	for(int i = 0; i<n+1; i++)
	{
		for(int j = 0; j <= min(i,k); j++)
		{
			if(j == 0|| j == i)

				dp[i][j] = 1;

			else
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

		}
			
	}
	return dp[n][k];
}

//Space Complexity: O(k)

int biCoeff(int n, int k)
{
	int c[k+1];
	
	memset(c, 0, sizeof(c));
	c[0] = 1;
	

	for(int i = 1; i <= n; i++)
		for(int j = min(i,k); j > 0; j--)
			c[j] = c[j] + c[j-1];

	return c[k];
}

int main()
{
	
    freopen("out.out", "w", stdout);
    int n = 5, k = 2;
    cout<< "Value of C (" <<n<<","<<k<<") is "<< binomialCoeff(n, k) <<endl ;
    cout<< "Value of C (" <<n<<","<<k<<") is "<< biCoeff(n, k) ;
    return 0;
}