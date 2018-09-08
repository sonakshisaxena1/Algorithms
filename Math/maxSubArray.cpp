//Maximum subarray size, such that all subarrays of that size have
// sum less than k


//using biary search
// O(nlogn)
#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int prefixSum(int k)
{
	b.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
		b.push_back(b[i-1] + a[i]);
	int size = 0;
	for(int i = 0; i < a.size(); i++)
		if(b[i] < k && b[i+1] >= k)
			{
				size = i;
				break;
			}

	int l = 0, r = size, i;
	int ans = -1;
	while(l <= r)
	{
		int mid = (l+r)/2;
		for(i = mid; i <= size; i++)
			if(b[i] - b[i-mid] >= k)
				break;
		if(i == size+1)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;

	}
 	return ans;
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n,k, sum = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(x > k)
		{
			cout << "-1";
			return 0;
		}
		a.push_back(x);

	}
	cout<< (prefixSum (k));
	return 0;

}