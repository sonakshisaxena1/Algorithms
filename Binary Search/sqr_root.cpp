//Return square root of a number, if not perfect square then return floor
#include<bits/stdc++.h>
using namespace std;

//O(logA)
int find_sqrt(int A)
{
    long long x = A;
    if (x == 0 || x == 1) 
       return x;
 
    
    long long start = 1, end = x/2, ans;   
    while (start <= end) 
    {        
        long long mid = (start + end) / 2;
 
        if (mid*mid == x)
            return mid;
 
        if (mid*mid < x) 
        {
            start = mid + 1;
            ans = mid;
        } 
        else 
            end = mid - 1;        
    }
    return ans;
}

int main()
{
    
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    cout << find_sqrt(n);
    return 0;
}