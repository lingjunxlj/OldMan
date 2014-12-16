#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long p[2], T[1001][2], n, t, sum, head, now[500100], dp[500100];
long long max (long long a, long long b)
{
    return a > b? a : b;
}
int main()
{
    int Q, P = 0;
    scanf("%d", &Q);
    while(Q--)
    {
        scanf("%I64d %I64d %I64d %I64d", &n, &t, &p[0], &p[1]);
        sum = 0;
        head = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d %I64d", &T[i][0], &T[i][1]);
            for (int j = 0; j < 2; j++)
            {
                if (T[i][j] >= 2 * t)
                {
                    long long x = (T[i][j] - t)/t;
                    sum += x*p[j];
                    T[i][j] -= x*t;
                }
                for (int k = 1; k <= T[i][j]; k++)
                    now[++head] = p[j];
            }

        }
        memset(dp, 0, sizeof(dp));

        for (int i = head; i >= 1; i--)
            dp[i] = max(dp[i + 1], dp[i + t] + now[i]);

        printf("Case %d: %I64d\n", ++P, dp[1] + sum);

    }
}
