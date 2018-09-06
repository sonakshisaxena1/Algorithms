#include<bits/stdc++.h>
using namespace std;
vector<int> a;


void merge(int l ,int mid, int r)
{
	int n1 = mid -l - 1;
	int n2 = r - mid;
	int left[n1], right[n2];
	for(int i = 0 ;i < n1; i++)
		left[i] = a[i + l];
	for(int i = 0 ; i < n2; i++)
		right[i] = a[i + mid + 1];
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		a[k] = right[j];
		j++;
		k++;
	}

}
void mergeSort(int l, int r)
{
	if(l < r)
	{
		int mid = l + (r-1)/2;
		mergeSort(l, mid);
		mergeSort(mid+1, r);
		merge(l, mid, r);
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
		a.push_back(x);
	}
	mergeSort(0, n-1);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;

}