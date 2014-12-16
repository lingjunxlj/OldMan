#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 200000;
int n, dp[MAXN][5];
int main()
{
    int i, j, k;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (k = 1;; k++)
    {
        if(k * k > MAXN)
        break;

        for(i = 0; i <= MAXN; i++)
        {
            if(i + k * k > MAXN)
            break;

            for(j = 1; j <= 4; j++)
            dp[i + k * k][j] += dp[i][j - 1];
        }
    }
    while(scanf("%d", &n) != EOF && n)
    printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]);
}
