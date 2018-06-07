#include<bits/stdc++.h>
using namespace std;


int fib(int n)
{
	int lookup[n];
	lookup[0] = 0;
	lookup[1] = 1;

	for(int j = 2; j<=n; j++)
	{
		lookup[j] = lookup[j-1] + lookup[j-2];
	}
	return lookup[n];

}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout); 
	int n;
	cin >> n;
	cout<< "The fibonacci number is: "<<fib(n);
	return 0;
}