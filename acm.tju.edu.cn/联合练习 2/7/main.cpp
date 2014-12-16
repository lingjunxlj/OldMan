#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 200;
int dp[MAX][MAX];
int main()
{
    int n, w;
    while (scanf("%d %d", &n, &w) != EOF)
    {
        int i, j, k, p;
        memset(dp, 0,sizeof(dp));
        int box, m;
        int goods, value;
        for(i = 1; i <= MAX; ++i)
			dp[0][i] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &box);

            scanf("%d", &m);
			for(j = 0; j < m; j++)
			{
                scanf("%d %d", &goods, &value);
                for(k = w; k >= 0; k--)
                {
                    dp[i][k] = max(dp[i-1][w-box-k]+value, dp[i-1][k]);

                }
			}
        }
        printf("%d\n",dp[n][w]);
    }
}
