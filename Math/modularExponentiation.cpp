//Finding out (x^y)%p
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, p;
	cin >> x >> y >> p;
	int result = 1;
	while(y > 0)
	{
		if(y&1)
			result *= x;
		y = y >> 1;
		x *= x;
	}
	result %= p;
	cout << result;
	return 0;
}