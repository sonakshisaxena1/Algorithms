#include<bits/stdc++.h>
using namespace std;

//Find the target element in the circular sorted list

int circular_sorted(vector<int> A)
{
    int start = 0;
    int n = A.size();
    int end = A.size() - 1;
    while(start <= end)
    {
        
        if(A[start] <= A[end])
            return start;

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

int binarySearch(const vector<int> &A, int start, int end, int key){
    int mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key)
        {
            return mid;
        }
        else if(A[mid] > key)
        {
            end = mid-1;
        }
        else
        { // A[mid] < key
            start = mid+1;
        }
    }
    return -1;
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
    int pivot = circular_sorted(A);
    if(B == A[pivot]){
       cout << pivot;
       return 0;
    }

    int result = binarySearch(A, 0, pivot-1, B);
    
    if(result == -1){
        int x = binarySearch(A, pivot+1, A.size()-1, B);   
        cout << x;
        return 0; 
    }
    
    cout << result;
    return 0;
   
}