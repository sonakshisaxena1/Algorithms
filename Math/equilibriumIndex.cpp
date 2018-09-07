#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	vector<int> a;
	int n, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		sum += x;
	}
	int leftSum = 0;
	for(int i = 0; i < n; i++)
	{
		leftSum = a[i];
		sum -= leftSum;
		if(leftSum == sum)
		{
			cout << i;
			return 0;
		}
	}
	cout << "None";
	return 0;

}