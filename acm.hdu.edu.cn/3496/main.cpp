#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[101], w[101];
int dp[101][1001];
int max(int a, int b)
{
    return a > b? a:b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, l;
        scanf("%d %d %d", &n, &m, &l);

        for (int i = 0; i < n; i++)
            scanf("%d %d", &c[i], &w[i]);

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= l; j++)
                dp[i][j] = -9999999;
        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
            for (int k = m; k >= 1; k--)
                for (int j = l; j>= c[i]; j--)
                {

                        dp[k][j] = max(dp[k][j], dp[k - 1][j - c[i]] + w[i]);
                }
        int Max = 0;
        for (int i = 0; i <= l; i++)
            if (Max < dp[m][i])
                Max = dp[m][i];
        printf("%d\n", Max);
    }
}
