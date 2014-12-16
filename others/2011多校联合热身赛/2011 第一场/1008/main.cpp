#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int x = sqrt(n);
        //printf("x == %d\n", x);
        int j = 0;
        int ans = 0;
        for (int i = x; i > j; i--)
        {
            if (sqrt(n - i*i) - (int)sqrt(n - i*i) < 1e-8 && sqrt(n - i*i) - (int)sqrt(n - i*i) > -1e-8)
            {
                j = (int)sqrt(n - i*i);
                //printf("j == %d\n", j);
                if (j == i)
                    ans += 4;
                else
                    ans += 8;
                if (j == 0)
                    ans -= 4;
            }
        }
        printf("%d\n", ans);
    }
}
