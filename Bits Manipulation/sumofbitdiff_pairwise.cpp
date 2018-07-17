#include<bits/stdc++.h>
using namespace std;


//O(n)
int sum(vector<int> A)
{
	int ans = 0;

	for(int i = 0; i < 32; i++)
	{
		int count = 0;
		for(int j = 0; j < A.size(); j++)
		{
			if(A[j] & (1 << i))
				count++;
		}

		ans += count * (A.size() - count) * 2;
	}
	return ans;
}

//O(n^2)
int sum_2(vector<int> A)
{
   int sum = 0;
   for(int i = 0; i < A.size(); i++)
   {
        for(int j = i+1; j < A.size(); j++)
        {
            int x = A[i]^A[j];
            int cnt = 0;
            while(x)
            {
                if((x & 1) == 1)
                    cnt++;
                x >>= 1;
            }
            sum = (sum + cnt) % (1000000007);

        }
   }

   return 2*sum;

}

int main()
{
    freopen("test.out","w", stdout);
    freopen("test.in", "r", stdin);
    vector<int> A;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    
    cout << sum(A) << endl;

    return 0;
}