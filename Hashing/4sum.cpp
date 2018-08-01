#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<vector<int> > fourSum(vector<int> A, int B) {
    vector<vector<int> > ans;
    sort(A.begin(), A.end());
    int i = 0;
    int j;
    while(i < A.size() - 3)
    {
      j = i+1;

      while(j < A.size() - 2)
      {
        int num = B -( A[i] + A[j]);
        int l = j+1;
        int r = A.size() - 1;
        while(l < r)
        {
          int sol = A[l] + A[r];
          if(sol == num)
          {
            vector<int> temp;
            temp.push_back(A[i]);
            temp.push_back(A[j]);
            temp.push_back(A[l]);
            temp.push_back(A[r]);
            
            ans.push_back(temp);
            temp.erase(temp.begin(), temp.end());
            while(A[l] == A[l+1] && l < A.size() - 1 )
              l++;
            while(A[r] == A[r-1] && r > 0 )
              r--;
            l++;
            r--;

          }

          else if(sol < num)
            l++;
          else
            r--;

        }

        while(A[j] == A[j+1])
            j++;
        

        j++;
      }

      while(A[i] == A[i+1])
          i++;
      i++;
    }
    
    return ans;
}



int main()
{

  //freopen("test.in", "r", stdout);
  //freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> A;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  int B;
  cin >> B;
  vector< vector< int > > ans = fourSum(A, B);
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;

}