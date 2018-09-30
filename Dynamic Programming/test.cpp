//prime set subsequences
#include<bits/stdc++.h>
using namespace std;

int solve(int A)
{
	int result = 1; 
    int dp[A+1];
    dp[1] = 1, dp[2] = 1, dp[3] = 1;
    for(int i = 4; i <= A; i++)
    {
        int result = 1;
        for(int j = 1; j < i; j++)
        {
            if(i%j == 0)
                result = (result * j * dp[j])%1000000007;
            cout << result << "\n";
        }

        dp[i] = result;
    }
     for(int i = 1; i <= A; i++)
        	cout << dp[i] << " ";
        cout << "\n";
    return dp[A]%1000000007;
}
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int n;
	cin >> n;
	cout<< solve(n);
	return 0;
}
/*
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);`
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
			int x;
			cin >> x;
			A.push_back(x);
	}
	cout << solve() ;
	return 0;

}*/