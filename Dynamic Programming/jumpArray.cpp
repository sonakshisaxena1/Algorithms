#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N];
vector<int> A;

int jumpArray()
{
    int visited[A.size()];
    for(int i = 0; i < A.size(); i++)
        visited[i] = 0;
    visited[0] = 1;
    for(int i = 0; i < A.size(); i++)
    {
        if(visited[i] == 0)
            break;
        for(int j = 1; j <= A[i]; j++)
        {
            if(i+j >= A.size())
                break;
            else
            {
                visited[i+j] = 1;
            }
        }
        if(visited[A.size() - 1] == 1)
            return 1;
    }

  return visited[A.size() - 1];
  
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << jumpArray();
    

    return 0;
}