#include<bits/stdc++.h>
using namespace std;

int findRotations(string s)
{
	string temp = s + s;
    for (int i = 1; i <= s.length(); i++) 
    {
 
        string sub = temp.substr(i, s.size());
        if (s == sub)
            return i;
    }
    return s.length();
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string s;
	cin >> s;
	cout << findRotations(s);
}