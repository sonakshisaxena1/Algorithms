#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > avgset(vector<int> &A) {
    int n = A.size();
    int leftSum = 0;
    vector<vector<int>> ans;
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += A[i];
    
    int i;
    for( i = 0; i < n; i++)
    {
        leftSum += A[i];
        int rightSum = sum - leftSum;
        if((leftSum * (n-i-i)) == (rightSum * (i+1)))
            break;
    }
    
    if(i != 0)
    {
        vector<int> v;
        for(int j = 0; j <= i; j++)
        {
            v.push_back(A[j]);
 
        }
        ans.push_back(v);
        v.clear();
        for(int j = i+1; j < n; j++)
            v.push_back(A[j]);
        ans.push_back(v);
    }
    
    return ans;
}

int main()
{
    vector<int>A;
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);

    }
    vector<vector<int>> ans = avgSet(A);
    return 0;

}