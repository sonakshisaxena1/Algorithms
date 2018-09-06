#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

void insertionS()
{
	int i, j, key;
	for( i = 1; i < arr.size(); i++)
	{
		key = arr[i];
		j = i - 1;
		while( (j >= 0 ) && (arr[j] > key))
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
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
	insertionS();
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

