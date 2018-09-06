#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

void bubble()
{
	int j;
	int i = arr.size() - 1;
	while( i >= 0 )
	{
		bool flag = false;
		for(j = 0; j <= i; j++)
		{
			if(arr[j+1] < arr[j])
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j]= temp;
				flag = true;
			}
		}
		if(flag == false)
			break;
		i--;
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
	bubble();
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

