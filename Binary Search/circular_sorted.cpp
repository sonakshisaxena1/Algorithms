#include<bits/stdc++.h>
using namespace std;

//O(log n)
//Finding Pivot

int circular_sorted(vector<int> A)
{
    int start = 0;
    int n = A.size();
    int end = A.size() - 1;
    while(start <= end)
    {
        
        if(A[start] <= A[end])
            return (start);

        int mid = (start+end)/2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if(A[mid] <= A[next] && A[mid] <= A[prev])
            return mid;
        else if(A[mid] <= A[end])
            end = mid - 1;
        else if(A[mid] >= A[start])
            start = mid + 1;
    }
    return -1;
}

int main()
{
    
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    vector<int> A;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    int index = circular_sorted(A);
    cout << "Times rotated: " << index << "Minimum element: " << A[index] ;
}