//Find the target value, if not present return the index where it should be inserted
#include<bits/stdc++.h>
using namespace std;

int find_sqrt(vector<int> A, int B)
{
    
    
    int start = 0, end = A.size()-1, ans;   
    while (start <= end) 
    {        
        int mid = (start + end) / 2;
 
        if (A[mid] == B)
            return mid;
 
        if (A[mid] < B) 
        {
            start = mid + 1;
            ans = mid + 1;
            
        } 
        else 
        {
            end = mid - 1;  
            ans = mid;
        }      
    }
    return ans;
}

int main()
{
    
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, B;
    vector<int>A;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cin >> B;
    cout << find_sqrt(A,B);
    return 0;
}