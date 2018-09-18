
/*
Smallest subarray with sum greater than a given value */

#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int smallestSubArray(int x)
{
	int start = 0, end = 0;
	int min_length = a.size()+1, curr_sum = 0;
	while(end < a.size())
	{
		while(curr_sum <= x && end < a.size())
		{
			curr_sum += a[end];
			end++;
		}
		while(curr_sum > x && start < a.size())
		{
			if(end - start <min_length)
				min_length = end - start;
			curr_sum -= a[start++];
		}
	}
	
	return min_length;
		
}

int main()
{

	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n,sum;
	cin >> n >> sum;
	for(int i =0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	int res = smallestSubArray(sum);
	if(res == a.size()+1)
		cout << "not possible";
	else
		cout << res;
	
	return 0;
}
