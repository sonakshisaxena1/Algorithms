//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> A;
vector<int> B;


int op()
{
	if(A.size() == 0)
		return 0;
	
	int maximum = 1;
	unordered_map<double, int> map;
	

    for(int i = 0; i < A.size(); i++)
    {
    	int duplicate = 1;
		int vertical = 0;
		

        for(int j = i+1; j < A.size(); j++)
        {
        	if(A[i] == A[j])
        	{
        		if(B[i] == B[j])
        			duplicate++;
        		else
        			vertical++;
        	}
        	else
        	{
        		double slope = 0.0;
	            double x = A[j] - A[i];
	            double y = B[j] - B[i];
	            if(y != 0)
	            	slope = (1.0 * (y/x));
	            if(map.find(slope) != map.end())
	            	map[slope] += 1;
	            else
	            	map[slope] = 1;
	        }
        }

        unordered_map<double, int>:: iterator it = map.begin();
        while(it != map.end())
	    {
	    	int t = it->second;
	    	if(t + duplicate > maximum)
	        	maximum = (duplicate + t);
	        it++;
	    }

	    if((vertical + duplicate) > maximum)
	    {
	    	maximum = vertical + duplicate;
	    }

	    map.clear();

    }


    return maximum;
}

int main()

{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i] >> B[i];
	
	cout << op();
	return 0;
}