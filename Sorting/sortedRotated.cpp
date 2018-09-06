#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

int binary(int l, int r, int x)
{
	if(r < l)
		return -1;
	int mid = (l+r)/2;
	if(arr[mid] == x)
		return mid;
	else if(arr[mid] < x)
		return binary(mid + 1, r, x);
	else
		return binary(l, mid - 1, x);
}

int findPivot(int l, int r)
{
	if(r < l)
		return -1;
	if(l == r)
		return l;
	int mid = (l+r)/2;
	if(mid < r && arr[mid] > arr[mid+1])
		return mid;
	if(l < mid && arr[mid-1] > arr[mid])
		return mid - 1;
	if(arr[l] >= arr[mid])
		return findPivot(l, mid-1);
	return findPivot(mid + 1, r);
}
		
int findIndex(int l, int r, int x)
{
	int pivot = findPivot(l, r);
	if(pivot == -1)
		return binary(l,r,x);
	if(arr[pivot] == x)
		return x;
	else if(arr[0] <= x)
		return binary(0, pivot - 1, x);
	return binary(pivot + 1, arr.size()-1, x);


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
		arr.push_back(x);
	}
	int key;
	cin >> key;
	cout << findIndex(0, n-1, key) << " ";
	return 0;
}

