//Largest contagious subarray sum 0 length


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> arr;



int op()
{
	unordered_map<int, int> presum;
 
    int sum = 0;        
    int max_len = 0;    
 
    for(int i=0; i< arr.size(); i++)
    {
        
        sum += arr[i];
 
        if (arr[i]==0 && max_len==0)
            max_len = 1;
        if (sum == 0)
            max_len = i+1;
 
        
        if(presum.find(sum) != presum.end())
        {
            
            max_len = max(max_len, i-presum[sum]);
        }
        else
        {
            presum[sum] = i;
        }
    }
 
    return max_len;

}

int main()

{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	cout << op();
	
	return 0;
}