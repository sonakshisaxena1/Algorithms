#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
	string res = "";
	int s = 0;
	int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
    	s += (i>=0) ? a[i] - '0' : 0;
    	s += (j>=0) ? b[i] - '0' : 0;
    	res = char(s%2 + '0') + res;
    	s = s/2;
    	i--;
    	j--;
    }
    return res;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string A, B;
	cin >> A >> B;
	
	cout << add(A, B);
	

	return 0;
}