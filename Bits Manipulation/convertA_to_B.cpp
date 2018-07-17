//Count the number of flips required to convert A to B
#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int A, B;
    cin >> A >> B;
    int count = 0;
    while(B)
    {
        if(((A & 1) ^ (B & 1)) == 1) 
            count++;
               
        A >>= 1;
        B >>= 1;

    }
    cout << count;
}