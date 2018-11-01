
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


bool isBinaryNumber(int n)
{
	while(n > 0)
	{
		if((n%10 == 0 )|| (n%10 == 1))
			n /= 10;
		else
			return false;
	}
	return true;
}
int isDivisible(string t, int N)
{
	int r = 0; 
    for (int i = 0; i < t.length(); i++) 
    { 
        r = r * 10 + (t[i] - '0'); 
        r %= N; 
    } 
    return r; 
}

string solve(int n)
{
	if(isBinaryNumber(n))
	{
		string t = "";
		while(n>0)
		{
			if(n%10 == 0)
				t += "0";
			else
				t += "1";
			n /= 10;
		}
		reverse(t.begin(), t.end());
		return t;
	}
	queue<string> q;
	set<int>visit;
	string t = "1";
	q.push(t);
	while(!q.empty())
	{
		string u = q.front();
		q.pop();
		int r = isDivisible(u, n);
		if(r == 0)
			return u;
		else if(visit.find(r) == visit.end())
		{
			visit.insert(r);
			q.push(u+"0");
			q.push(u+"1");

		}


	}
	return "";

}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	
	cout << solve(n);
	
	return 0;
}

