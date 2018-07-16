//O(nlogn)
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int min_XOR(vector<int> A)
{
    sort(A.begin(), A.end());
    int min_XOR = INT_MAX;
    for(int i = 0; i < A.size(); i++)
    {
        curr ^= A[i];
        min_XOR = min(min_XOR, curr);
    }

    return min_XOR;

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
    
    cout << min_XOR(A) << endl;
 
    return 0;
}