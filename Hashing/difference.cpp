//Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


int sum(vector<int> A, int B)
{ 	
	unordered_map<int, int> myMap;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(myMap.find(A[i]) == myMap.end())
        {
            myMap[A[i]] = 1;
        }
        else
        {
            myMap[A[i]] = 2;
        }
    }
    
    unordered_map<int, int> :: iterator it = myMap.begin();
    
    while(it != myMap.end())
    {
        int num = it->first - B;
        if(myMap.find(num) != myMap.end())
        {
            if(myMap.find(num) != it)
            {
                return 1;    
            }
            else
            {
                if(it->second > 1)
                {
                    return 1;
                }
            }
        }
        it++;
    }

  	return 0;

}
int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, B;
  cin >> n >> B;
  vector<int> A;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    A.push_back(x);
  }

  cout << sum(A, B);
  return 0;
}