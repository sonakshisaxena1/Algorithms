//Time complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> A) 
{
    

    
    stack<int> s;
 
    int max_area = 0; 
    int tp;  
    int current_area; 
                    
    int n = A.size();
   
    int i = 0;
    while (i < n)
    {
        
        if (s.empty() || A[s.top()] <= A[i])
            {
                s.push(i);
                i++;
            }
 
        else
        {
            tp = s.top();  
            s.pop();  
 
            current_area = A[tp] * (s.empty() ? i :i - s.top() - 1);
            max_area = max(max_area,current_area);
        }
    }
 
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        current_area = A[tp] * (s.empty()? i:i - s.top() - 1); 
        max_area = max(max_area,current_area);
    }
 
    return max_area;

 
}



int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	vector<int> v;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

	cout << largestRectangleArea(v);
	return 0;

}