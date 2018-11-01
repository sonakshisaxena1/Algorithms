//Maximum length of subarray with non negative integers
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> A;
int solve()
{

	int n = A.size();
	int prefix = 0, max_length = 0, curr_length = 0, x;
	for(int i = 0; i < n; i++)
	{
		x = prefix + A[i];
		if(x < prefix)
		{
			prefix = 0;
			max_length = max(max_length, curr_length);
			curr_length = 0;
			continue;
		}
		else
		{
			prefix = x;
			curr_length++;
		}
	}

	return max(max_length, curr_length);
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

