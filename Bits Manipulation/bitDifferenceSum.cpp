#include<bits/stdc++.h>
using namespace std;
vector<int> a;

int bitDifferenceSum()
{
	int ans = 0,count;
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < a.size(); j++)
		{
			count = 0;
			int x = a[i]^a[j];
			while(x)
			{
				if(x&1)
					count++;
				x>>=1;
			}
			ans+=count;
		}
	}
	return ans;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << bitDifferenceSum();
	return 0;

}