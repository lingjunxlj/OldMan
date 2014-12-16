#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[1000000][141];
int w[141];
int c[141];
int main()
{
    int i, j;
    int n, m, l;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &m, &l);
        for(i=0;i<=m;i++)
        memset(dp[i],0,sizeof(dp[i]));

        for (i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &c[i]);

        int t;
        for(i = 1; i <= n; i++)
        {
            for(t = l; t >= w[i]; t--)
            {

                for(j = m; j >= 1; j--)
                dp[t][j] = max(dp[t][j], dp[t - w[i]][j - 1] + c[i]);
            }
        }

        printf("%d\n", dp[l][m]);
    }
}
