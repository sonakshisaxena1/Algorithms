//x & (x-1) is used for stripping off the lowest set bit

#include<bits/stdc++.h>
using namespace std;

int bits_2(int A)
{
    int count = 0;
    while(A != 0)
    {
        A = A & (A-1);
        count++;
    }
    return count;
}

int bits(int A)
{   
    if(A == 0)
        return 0;

    int cnt = 0;
    string s = to_string(A);
    int i = 0;
    
    while(A != 0)
    {
        if((A & 1) == 1) 
            cnt++;
        
        A = A >> 1;
       
    }

    return cnt;
}



int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int x;
    cin >> x;
    cout << bits(x) << endl;
    cout << bits_2(x);
    return 0;
}