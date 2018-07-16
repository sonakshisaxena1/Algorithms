//Find the only non-repeated number if every other number in the array is repeated twice
#include<bits/stdc++.h>
using namespace std;
int main()
{;
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

    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp ^= A[i];
    }

    cout << temp;
    return 0;
}