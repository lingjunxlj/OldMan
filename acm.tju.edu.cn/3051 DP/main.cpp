#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double dp[90][270];
int main()
{
    int i, j, k, n, m;
    double r1, r2, r3, sum;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
        break;

        scanf("%d %d %d", &i, &j, &k);
        r1 = i * 1.0 / (i + j + k);
        r2 = j * 1.0 / (i + j + k);
        r3 = k * 1.0 / (i + j + k);
        memset(dp, 0, sizeof(dp));
        dp[1][0] = r3;
        dp[1][1] = r2;
        dp[1][3] = r1;
        for(i = 2; i <= n; i++)
        {
            for(j = 0; j <= 3 * i; j++)
            {
                if(j <= 0)
                    dp[i][j] = dp[i - 1][j] * r3;

                else if(j <= 1)
                    dp[i][j] = dp[i - 1][j] * r3 + dp[i - 1][j - 1] * r2;

                else
                    dp[i][j] = dp[i - 1][j] * r3 + dp[i - 1][j - 1] * r2 + dp[i - 1][j - 3] * r1;
            }
        }

        sum = 0.0;

        for(i = m; i <= 3 * n; i++)
            sum += dp[n][i];

        printf("%.1lf\n", sum * 100);
    }
}
