//Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.
//O(n)
//Another solution is to sort the array and except the first element keep on swapping the elements in pairs but it will take O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int a[100];
void zigzag(int n)
{	
	bool flag = true; // flag true = '<'
	for(int i = 0; i < n-1; i++)
	{
		if(flag)
		{
			if(a[i] > a[i+1])
				swap(a[i], a[i+1]);
		}
		else
		{
			if(a[i] < a[i+1])
				swap(a[i],a[i+1]);
		}
		flag = !flag;
	}
}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n;
	cin >> n;
	for(int i =0; i < n; i++)
		cin >> a[i];
	zigzag(n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}