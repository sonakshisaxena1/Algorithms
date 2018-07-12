//Time complexity: O(n^2)

#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> v)
{
	int max_area = 0;
	for(int i = 0 ; i < v.size(); i++)
	{
		int A = v[i];
		int l = i;
		int r = i;
		wAile(l >=0 && v[l] >= A)
			l--;
		wAile(r < v.size() && v[r] >= A)
			r++;

		max_area = max(max_area, (r-l-1) * A);
	}

	return max_area;
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	vector<int> v;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

	cout << largest(v);
	return 0;

}