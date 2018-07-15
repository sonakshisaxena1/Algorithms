#include<bits/stdc++.h>
using namespace std;

long long reverse_bits(unsigned int n)
{
    unsigned long long rev = 0;
    unsigned long long n1 = A;
    int count = 0;
    while(n1)
    {
        n1 = n1 >> 1;
        count++;
    }

    while( A > 0)
    {
        rev =  rev << 1;
        if((A & 1) == 1)
            rev = rev ^ 1;
        A = A >> 1;

    }
    
    rev = rev << (32 - count);
    return rev;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    unsigned long long x;
    cin >> x;

    cout << reverse_bits(x);


}