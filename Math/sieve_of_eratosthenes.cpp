#include<iostream>
using namespace std;

void sieve(int n)
{
	bool number[n+1];
	memset(number, true, n+1); //O(n)
	for(int i = 2; i <= n; i++) //O(nloglogn)
	{
		if(number[i] == true)
		{
			for(int k = 2; k <= n/i; k++)
				
					number[i*k] = false;
			
		}
	}

	for(int i = 2; i <= n; i++)
		if(number[i] == true)
			cout << i << endl;

}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	sieve(n);
	return 0;
}