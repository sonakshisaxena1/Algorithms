//number of subarrays with sum equal zero
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> A;
int solve()
{
	unordered_map<int, int> m;
	int n = A.size();
	int prefix;
	prefix = 0;
	m[0] = 1;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		prefix = prefix+ A[i];
		if(m.find(prefix) == m.end())
				m[prefix] = 1;
		else
		{
			ans += m[prefix];
			m[prefix]++;
			cout << i << " " << ans << endl;
			
		}
	}

	return ans;
}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		A.push_back(x);
	}

	cout<< solve();
	return 0;
}