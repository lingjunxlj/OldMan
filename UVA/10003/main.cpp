#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1001][1001], n, a[51];
const int inf = 2000007;
int min(int a, int b)
{
    return a < b? a:b;
}
int d(int x, int y)
{
    bool fg = false;
    if(dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = inf;
    for (int i = 1; i <= n; i++)
        if (x < a[i] && a[i] < y)
        {
            dp[x][y] = min(dp[x][y], d(x, a[i]) + d(a[i], y) + y - x);
            fg = true;
        }
    if(!fg)
        dp[x][y] = 0;
    return dp[x][y];
}
int main()
{
    int l;
    while(scanf("%d", &l), l)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for (int i = 0; i <= l; i++)
            for (int j = 0; j <= l; j++)
                dp[i][j] = -1;

        //memset(dp, -1, sizeof(dp));
        d(0, l);
        printf("The minimum cutting is %d.\n", dp[0][l]);
    }
}
