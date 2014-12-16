#include <cstdio>
#include <cmath>
const int inf = 0x7fffff;
int min(int a, int b)
{
    return a>b?b:a;
}
int dp[10001];
int p[501], w[501];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int e, f;
        scanf("%d %d", &e, &f);
        int temp = f - e;
        int n, i, j;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d %d", &p[i], &w[i]);

        for (i = 1; i <= temp; i++)
        dp[i] = inf;
        dp[0] = 0;
        for (i = 0; i < n; i++)
            for (j = w[i]; j <= temp; j++)
                dp[j] = min( dp[j], dp[j - w[i]] + p[i]);

        if (dp[temp] == inf)
        printf ("This is impossible.\n");
        else
        printf ("The minimum amount of money in the piggy-bank is %d.\n", dp[temp]);
    }
}


