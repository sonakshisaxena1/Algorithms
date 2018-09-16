//Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value. Expected Time Complexity is O(n2).
#include<bits/stdc++.h>
using namespace std;
vector<int>a;

int countTriplets(int sum)
{
	int ans = 0;
	sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++)
	{
		int j = i+1, k = a.size()-1;
		while(j < k)
		{
			if(a[i]+a[j]+a[k] >= sum)
				k--;
			else
			{
				ans += k-j;
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out","w",stdout);
	int n,sum;
	cin >>n>> sum;
	for(int i =0;i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << countTriplets(sum);
	return 0;
}