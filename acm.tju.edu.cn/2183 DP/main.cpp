#include <cstdio>
int map[101][101];
int dp[101][101];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i <=n + 1; i++)
            for (int j = 0; j <=n + 1; j++)
            dp[i][j] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        for (int i = 0; i < n; i++)
            dp[0][i] = map[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + map[i][j];
                else if (j == 0)
                    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j + 1]) + map[i][j];
                else
                    dp[i][j] = max( max(dp[i - 1][j],dp[i - 1][j - 1]) , dp[i - 1][j + 1]) + map[i][j];
            }
        int MAX = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[n - 1][i] > MAX)
                MAX = dp[n - 1][i];
        }
            printf("%d\n", MAX);
    }
}
