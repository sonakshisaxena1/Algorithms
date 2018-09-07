#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool prefixSum()
{
	sort(a.begin(), a.end());
	vector<int> pf;
	pf.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
	{
		pf[i] = pf[i-1] + a[i];
		if(pf[i] == 0)
			return true;
	}
	return false;
}




int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	if(prefixSum)
		cout<< "true";
	else
		cout << "false";
	return 0;

}