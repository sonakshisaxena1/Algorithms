#include<bits/stdc++.h>
using namespace std;



int first_occurrence(vector<int> A, int B)
{
    int start = 0;
    int end = A.size() - 1;
    int result = -1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(A[mid] == B)
        {
            result = mid;
            end = mid - 1;
        }
        else if(A[mid] > B)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return result;
}
int main()
{
    
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    vector<int> A;
    int n, B;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    cin >> B;
    cout << first_occurrence(A, B);
}