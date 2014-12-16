#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long n;
int main()
{
    while(scanf("%I64d", &n), n)
    {
        long long temp = n;
        int len = 0;
        while(temp)
        {
            temp /= 10;
            len++;
        }
        long long one = 1;
        for (int i = 0; i < len; i++)
            one = one*10 + 1;
        while(1)
        {
            if (n%one == 0)
            {
                n /= one;
                break;
            }
            one /= 10;
        }
        printf("%I64d\n", n);
    }
}
