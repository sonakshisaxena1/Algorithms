/*ou are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>A;
vector<int>B;
vector<int>C;
int checkMax(int a, int b, int c){
    int max = a;
    if(max < b){
        max = b;
    }
    if(max < c){
        max = c;
    }
    
    return max;
}

int minimize() 
{
    
    
    int i = 0, j = 0, k = 0;
    int sol = INT_MAX;
    int temp, temp1, temp2, temp3;
    
    while(i < A.size() || j < B.size() || k < C.size()){
        sol = min(sol, checkMax(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])));
        
        if(i+1 < A.size()){
            temp1 = checkMax(abs(A[i+1] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i+1]));
        }
        else{
            temp1 = INT_MAX;
        }
        if(j+1 < B.size()){
            temp2 = checkMax(abs(A[i] - B[j+1]), abs(B[j+1] - C[k]), abs(C[k] - A[i]));
        }
        else{
            temp2 = INT_MAX;
        }
        if(k+1 < C.size()){
            temp3 = checkMax(abs(A[i] - B[j]), abs(B[j] - C[k+1]), abs(C[k+1] - A[i]));
        }
        else{
            temp3 = INT_MAX;
        }

        temp = min(temp1, temp2);
        temp = min(temp, temp3);
        
        if(temp == INT_MAX){
            return sol;
        }
        else if(temp == temp1){
            i++;
        }
        else if(temp == temp2){
            j++;
        }
        else{
            k++;
        }
        
    }
    
    
    return sol;
}


int main()
{

  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n1, n2, n3 ;
  cin >> n1 >> n2 >> n3 ;
  for(int i = 0; i < n1; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  for(int i = 0; i < n2; i++)
  {
    int x;
    cin >> x;
    B.push_back(x);
  }

  for(int i = 0; i < n3; i++)
  {
    int x;
    cin >> x;
    C.push_back(x);
  }

  cout << minimize
  ();
  return 0;
}