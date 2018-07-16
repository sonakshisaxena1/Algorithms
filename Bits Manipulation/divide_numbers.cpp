#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
     
    unsigned long long tmp = abs((long long)dividend);
    unsigned long long tmp2 = abs((long long)divisor);
            
    unsigned long c = 1;
    while (tmp2 < tmp)
    {
        tmp2 = tmp2<<1;    
        c = c<<1;
    }
     
    long long res = 0;
    while (tmp >= abs((long long)divisor))
    {
        if (tmp2 <= tmp)
        {
            tmp -= tmp2;
            res = res + c;
        }

        tmp2 = tmp2 >> 1;
        c = c >> 1;    
    }
     
    return (sign*res >= INT_MAX ||  sign*res < INT_MIN) ? INT_MAX : sign*res;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int A, B;
    cin >> A >> B;

    cout << divide(A, B);
    return 0;


}