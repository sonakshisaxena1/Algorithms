#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w",stdout);
	string s, t;
	cin >> s >> t;
	int cnt1[26];
	memset(cnt1, 0, sizeof(cnt1));
	for(int i = 0; i < (max(s.size(), t.size())); i++)
	{
		if(i < s.size())
			cnt1[(int)s[i] - 'a']++;
		if(i < t.size())
			cnt1[(int)t[i] - 'a']--;
	}

	for(int i = 0; i < 26; i++)
		if(cnt1[i] != 0)
			cout << "No";
	cout << "Yes";
	return 0;
}