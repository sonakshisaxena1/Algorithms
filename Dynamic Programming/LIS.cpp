#include <bits/stdc++.h>
using namespace std;
vector<int> A;


int LIS()
{
    int n = A.size();
    int list[n];
    for(int i = 0; i < n; i++)
        list[i] = 1;
    
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++) 
            if((A[j] < A[i])  && (list[i] < list[j] + 1))
                list[i] = list[j] + 1;

    int max_length = 0;
    for(int i = 0; i < n; i++)
        if(max_length < list[i])
            max_length = list[i];
    return max_length;

}
int main()
{
	ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << LIS();
	
	
	return 0;
}