#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[22][1011], val[22][1011];
int max(int a, int b)
{
    return a > b? a : b;
}
int max_3(int a, int b, int c)
{
    return max(a, max(b, c));
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &val[i][j]);
                dp[i][j] = 0;
            }
        for(int i = 0; i <= n; i++)
            dp[0][i] = dp[i][0] = -1000;

        dp[0][1] = dp[1][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                int Max = -1000;
                for (int k = 2; j/k >= 1; k++)
                    if (j % k == 0 && dp[i][j/k] > Max)
                        Max = dp[i][j/k];
                dp[i][j] = max_3(dp[i - 1][j], dp[i][j - 1], Max) + val[i][j];
            }

        printf("%d\n", dp[n][m]);


    }
}
