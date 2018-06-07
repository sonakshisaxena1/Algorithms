#include<bits/stdc++.h>
using namespace std;
int lookup[100];

int fib(int n)
{
	if(lookup[n] == -1)
	{
		if(n<=1)
			lookup[n] = n;
		else
			lookup[n] = fib(n-1) + fib(n-2);
	}

	return lookup[n];
}

int main()
{
	freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout); 
	int n;
	cin >> n;

	for(int i = 0 ;i < 100;i++)
		lookup[i] = -1;

	cout<< "The fibonacci number is: "<<fib(n);
	return 0;
}