#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
	int x, n, d;
	cin >> x >> n >> d;
	if( x == 0)
	{
		cout << "0";
		return 0;
	}
	if (n == 0)
	{
		cout << "1";
		return ;
	}

	ll base;
	int ans = 1;
	while( n > 0)
	{
		if(n % 2 != 0)
		{
			ans = (ans * base) % d;
			n--;
		}
		else
		{
			base = (base * base) % d;
			n /= 2;
		}
	}

	if(ans < 0) 
		cout << (d + ans)%d;
	else
		cout << ans;
	return 0;
}