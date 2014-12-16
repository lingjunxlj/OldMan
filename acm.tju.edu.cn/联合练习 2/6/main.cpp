#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[100000][41];
int w[41];
int main()
{
    int i, j;
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for(i=0;i<=m;i++)
        memset(dp[i],0,sizeof(dp[i]));

        int k;
        scanf("%d", &k);

        for (i = 1; i <= k; i++)
        scanf("%d", &w[i]);

        int t;
        for(i = 1; i <= k; i++)
        {
            for(t = m; t >= w[i]; t--)
            {
                for(j = n; j >= 1; j--)
                dp[t][j] = max(dp[t][j], dp[t - w[i]][j - 1] + w[i]);
            }
        }
        printf("%d\n", dp[m][n]);
    }
}
