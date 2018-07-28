#include<bits/stdc++.h>
using namespace std;
vector<int>A;

int countTri()
{
     int ans = 0, n = A.size(), num = pow(10, 9) + 7;
    
    if(!n){
        return ans;
    }
    
    sort(A.begin(), A.end());
    
    for(int k = n - 1; k >= 0; k--)
    {
        int i = 0, j = k - 1;
        while(i < j)
        {
            long int miniSum = A[i] + A[j], maxi = A[k];
            if(miniSum > maxi){
                ans = (ans + (j - i)%num)%num;
                j--;
            }   
            else{
                i++;    
            }
        }
    }
    return ans;
}

int main()
{

  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n ;
  cin >> n ;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  cout << countTri();
  return 0;
}