#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool prefixSum()
{
	unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0 ; i < a.size() ; i++)
    {
        sum += a[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
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