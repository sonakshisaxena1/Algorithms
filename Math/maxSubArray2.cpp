//Maximum subarray size, such that all subarrays of that size have
// sum less than k


//using two pointers
// O(n)

#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int size(int k)
{
	int i =
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
	cout<< (size (k));
	return 0;

}