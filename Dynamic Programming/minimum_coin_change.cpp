// Given a total and coins of certain denomination with infinite supply, 
//what is the minimum number of coins it takes to form this total.
 
//Time Complexity = O(m*n)
 
 
#include<bits/stdc++.h>
using namespace std;
 
int minCoin(int coin[], int m, int n)
{
	int table[m+1][n+1];
 
	for(int i = 0; i < m; i++)
	{
		table[i][0] = 1;
		for(int j = 1; j < n+1; j++)
		{
			table[i][j] = 0;

			if(j >= coin[i])
				table[i][j] += table[i][j-(coin[i])]; //Coin i is used

			if(i > 0)
				table[i][j] += table[i-1][j]; //Coin i is not used
		}
	}
 
	return table[m-1][n];
 
}
int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int n = 11;
	int coin[] = {3,5,6,8};
	int m = sizeof(coin)/sizeof(coin[0]);
	cout << "minimum number of coins required are " << minCoin(coin, m, n);
	return 0;
 
}