#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n;
    while (1)
    {
        scanf("%lld", &n);
        if (n == 0)
        break;
        long long i;
        for (i = 1;; i++)
        {
            long long sum = 1, num = 0;
            while (1)
            {
                num += i * sum;
                sum *= 10;
                if (num > n)
                break;
                if (num == n)
                {
                    goto loop;
                }

            }
        }
        loop:;
        printf("%lld\n", i);
    }

}
