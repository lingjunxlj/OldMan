#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int max(int a, int b)
{
    return a > b? a:b;
}
int dp[1001][1001];
int sum[1001];
int main()
{
    int n, la, lb, s;
    while(scanf("%d", &n), n)
    {
        scanf("%d %d %d", &la, &lb, &s);
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            int num;
            scanf("%d", &num);
            sum[i] = sum[i - 1] + num;
        }
        int Max1 = 0;
        for (int i = 1; i <= n + 1 ; i++)
            for (int k = 0; k <= s; k++)
                for (int j = lb; j <= la; j++)
                {
                    if (i - j - 1 >= 0 && k > 0)
                    {
                        dp[i][k] = dp[i - 1][k] = max(dp[i - j - 1][k - 1] + (sum[i - 1] - sum[i - j - 1]) , dp[i - 1][k]);
                    if (dp[i][k] > Max1)
                        Max1 = dp[i][k];
                    }
                }
        printf("%d\n", sum[n] - Max1);

    }
}
