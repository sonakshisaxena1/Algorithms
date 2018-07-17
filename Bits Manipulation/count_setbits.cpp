#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.in", "r", "stdin");
	freopen("test.out", "w", "stdout");
	int x;
	cin >> x;
	int count = 0;
	while(x)
	{
		if((x & 1) == 1)
			count++;
		x >>= 1;
	}
	cout << count;
}