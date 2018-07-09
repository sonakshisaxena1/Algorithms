#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 2; i <= sqrt(n); i++)
	{
				
		if(n % i == 0)
			{	
				int count = 0;
				while(n % i == 0)
				{
					n = n/i;
					count++;
				}
				cout << "Number->" << i << " Exponent->"<< count << endl; 
			}

		
	}

	if(n != 1)
		cout << "Number->" << n << " Exponent->"<< 1 << endl;


	return 0;
}