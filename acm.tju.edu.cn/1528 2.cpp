#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long gcd(long long a, long long b)
{
    while(b != 0)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int t;
    cin>>t;
    while(t-- )
    {
        int n;
        long long l = 1;
        cin>>n;
        while(n--)
        {
            long long x;
            cin>>x;
            l = lcm(l, x);
        }
        cout<<l<<endl;
    }
    return 0;
}
