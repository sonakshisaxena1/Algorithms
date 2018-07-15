#include<bits/stdc++.h>
using namespace std;

bool isNumeric(int n)
{
    if(n >= 0 && n <=9)
        return true;
    return false;
}

int atoi(string A)
{
    if(A.size() == 0)
        return 0;
    
    int k = 0;
    if(A[0] == ' ')
        while(A[k] == ' ')
            k++;
            
    int sign = 1;
    long long res = 0;
    if(A[0] == '-')
        {
            sign = -1;
            k++;
        }
    
    if(A[0] == '+')
        {
            sign = 1;
            k++;
        }

    

    for(int i = k; A[i] != '\0' ; i++)
    {
        //if(res == 0 && A[i] == ' ')
          //  continue;
        if(isNumeric(A[i] - '0'))
            {
                    res = res*10 + (A[i] - '0');
            }
        else
            {
                if(res == 0)
                    break;
            }
    }
    
    if(res == 0)
        return 0;
    
    if(res > INT_MAX)
        if(sign == 1)
            return INT_MAX;
        else
            return INT_MIN; 
    return sign*res;
}


int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string A;
	cin >> A;
	cout << atoi(A);
	

	return 0;
}