#include<bits/stdc++.h>
using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
int romanToInt(string A) 
{
    int res = 0;
 
   
    for (int i = 0; i < A.length(); i++)
    {
       
        int s1 = value(A[i]);
 
        if (i+1 < A.length())
        {
      
            int s2 = value(A[i+1]);
 
          
            if (s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++; 
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}




int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string A;
	cin >> A;
	cout << romanToInt(A);
	

	return 0;
}