#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int const BASE = 8000;
int dp[25][8000 + BASE];
int c[25], w[25];
int main()
{
    int C, G;
    while(scanf("%d %d", &C, &G) != EOF)
    {
        for (int i = 1; i <= C; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= G; i++)
            scanf("%d", &w[i]);

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= C; i++)
            dp[1][BASE + w[1]*c[i]]++;

        for (int i = 2; i <= G; i++)
            for (int j = 1; j <= C; j++)
                for (int k = 2*BASE; k >= c[j]*w[i] ; k--)
                    if (dp[i - 1][k])
                        dp[i][k + c[j]*w[i]] += dp[i - 1][k];
        printf("%d\n", dp[G][BASE]);


    }
}
