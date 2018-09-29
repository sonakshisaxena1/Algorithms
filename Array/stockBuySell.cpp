//Famous Stock Buy Sell Problem
#include<bits/stdc++.h>
using namespace std;
vector<int> A;

iint stockBuySell()
{
	if(A.size() == 0)
		return 0;

	int sol = 0, minima = A[0];
	for(int i = 1; i < A.size(); i++)
	{
		if(A[i] < minima)
			minima= A[i];
		sol = max(sol, A[i] - minima);
	}
	return sol;
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < r; i++)
	{
			int x;
			cin >> x;
			A.push_back(x);
	}
	cout << stockBuySell() ;
	return 0;

}