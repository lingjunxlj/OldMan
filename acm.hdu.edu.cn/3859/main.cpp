#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long f(long long a, long long b)
{

    long long res = 0;

    if (a % b == 0)
        return a / b;

    if (a >= 3 * b)
    {
        res += a / b - 2;
        a = (a % b) + 2 * b;
    }
    if (a >= 2 * b)
    {
        if (a % 2 == b % 2)
            res += 3;
        else if (a % 2 == 0)
            res += 4;
        else
            res = -1;

    }
    else if ((a % 2 == b % 2))
        res += 3;
    else if (a % 2 == 0)
        return f(a, a - b);
    else
        res = -1;

    return res;
}

long long a, b;
int main()
{
    while (scanf("%I64d%I64d", &a, &b) != EOF)
    {
        long long res = f(a, b);
        if (res > 0)
            printf("%I64d\n", res);

        else
            printf("No Solution!\n");
    }
    return 0;
}
