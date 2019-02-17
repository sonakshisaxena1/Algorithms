#include<bits/stdc++.h>
using namespace std;
vector<int>A;
vector<int>adj[105];
bool visited[105];


void arrange()
{
	int n = A.size();
	bool flag[n];
	memset(flag, false, sizeof(flag));
	for(int i = 0; i < n; i++)
	{
		if(flag[i] == false && A[i] == A[i+1])
		{
			A[i] = 2*A[i];
			A[i+1] = 0;
			flag[i] =true;
			flag[i+1] = false;
		}

	}

	int last = 0;
	for(int i = 0; i < n; i++)
	{
		if(last == 0 && A[i] == 0)
			last = i;
		else if(A[i] != 0)
		{
			int temp = A[i];
			A[i] = 0;
			A[last] = temp;
			last = i;
		}
	}
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";

}
int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
       int x;
       cin >> x;
       A.push_back(x);
    }

    arrange();
    return 0;
    
}