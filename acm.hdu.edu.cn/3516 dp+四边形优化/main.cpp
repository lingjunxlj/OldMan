#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1000 + 10;
const int inf = 1 << 20;
int dp[MAXN][MAXN], s[MAXN][MAXN];
int x[MAXN], y[MAXN];
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &x[i], &y[i]);
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            s[i][0] = i;
        }

        for(int k = 1; k <= n-1; k++)
        {
            s[n-k+1][k] = n - 1;
            for(int i = n - k ; i >= 1; i--)
            {
                dp[i][i+k] = inf;
                for(int j = s[i][k-1]; j <= s[i+1][k]; j++)
                {
                    if(dp[i][j] + dp[j+1][i+k] + x[j+1] - x[i] + y[j] - y[i+k] < dp[i][i+k])
                    {
                        dp[i][i+k] = dp[i][j] + dp[j+1][i+k] + x[j+1] - x[i] + y[j] - y[i+k];
                        s[i][k] = j;
                    }
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
