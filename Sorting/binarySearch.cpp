#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

int binary(int l, int r, int x)
{
	int mid = (l+r)/2;
	if(arr[mid] == x)
		return mid;
	else if(arr[mid] < x)
		l = mid + 1;
	else
		r = mid - 1;
	binary(l, r, x);
	return -1;

}
/*
int binary1(int l, int r, int x)
{
	int mid = (l+r)/2 +1;
	if(arr[mid] == x)
		return mid;
	else if(arr[mid] < x)
		l = mid ;
	else
		r = mid - 1;
	binary1(l, r, x);
	return -1;
}*/
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
	cout << binary(0, n-1, key) << endl;
	//cout << binary1(0, n-1, key) << endl;
	return 0;
}

