#include<bits/stdc++.h>
using namespace std;
vector<int>a;
bool pythagoreantriplet()
{	
	for(int i = 0; i < a.size(); i++)
		a[i] = a[i]*a[i];
	sort(a.begin(), a.end());
	for(int i = a.size()-1; i >= 2; i--)
	{
		int l = 0, r = i-1;
		while(l < r)
		{
			if(a[l] + a[r] == a[i])
				return true;
			(a[l]+a[r] < a[i]) ? l++ : r--;
		}

	}
	return false;
}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int n;
	cin >> n;
	for(int i =0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	if(pythagoreantriplet())
		cout << "Found!";
	else
		cout << "Not found";
	
	return 0;
}