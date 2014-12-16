#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long gcd (long long n, long long m)
{
    if (m == 0)
        return n;
    else
        return gcd (m, n%m);
}
int main()
{
    long long n, m;
    while (cin>>n>>m)
    {
        if(!n && !m)
            break;
        if (gcd(n, m) == 1)
            printf("%I64d\n", n * m - n - m);
        else
            printf("Inf\n");
    }
}
