#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int GCD(int a,int b)
{
    if (b == 0)
    return a;

    return GCD (b , a % b);
}

int main()
{
    int y, z, i;
    long long t;
    while (scanf("%d", &y))
    {

        if (y == 0)
        break;

        int ans = 0;
        for (i = 1; i < y - 1; i++)
        {
            if (y % i == 0)
            continue;
            z = GCD(i, y);
            if (z > 1)
            ans++;
        }

        printf("%d\n",ans);
    }
}

