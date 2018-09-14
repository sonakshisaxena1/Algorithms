#include<bits/stdc++.h>
using namespace std;

int nextSparse(unsigned int n)
{
	int last_final = 0;
	vector<int> v;
	while(n != 0)
	{
		v.push_back(n&1);
		n >>= 1;
	}
	v.push_back(0);
	for(int i = 1; i < v.size()-1; i++)
	{
		if(v[i] == 1 && v[i-1] == 1 && v[i+1] != 1)
		{
			v[i+1] = 1;
			for(int j = i; j >= last_final; j--)
				v[j] = 0;
			last_final = i+1;
		}

	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++)
		ans += v[i]*(1<<i);
	return ans;

}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	unsigned int n;
	cin >> n;
	cout << nextSparse(n);
	return 0;

}