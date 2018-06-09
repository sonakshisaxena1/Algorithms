/* Given an array of integers where each element represents the max number of steps that
 can be made forward from that element. Write a function to return the minimum number 
 of jumps to reach the end of the array (starting from the first element). If an element
 is 0, then cannot move through that element.*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	int jumps[n+1];
	for(int i = 1; i<=n; i++)
		cin >> jumps[i];
 
	int dp[n+1];
 
	dp[1] = 0;
	for(int i = 2; i<=n; i++)
		dp[i] = INF;

	for(int i = 1; i<n; i++)
		for(int j = i+1; j<=min(n, i+jumps[i]); j++)
			dp[j] = min(dp[j], dp[i]+1);

 
	if(dp[n] == INF)
		cout << "Impossible to reach last element\n";
	else
		cout << dp[n] << "\n";
 
	return 0;
}