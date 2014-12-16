#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m, wide, price;
        int i, j, k, l;
        cin>>n;
        memset(dp, 0x7ffff, sizeof(dp));

        for (i = 1; i <= MAX ; i++)
            dp[0][i] = 0;

        for (i = 1; i <= n; i++)
        {
            cin>>m;

            for (j = 1; j <= m ; j++)
            {
                cin>>wide>>price;

                for(k = 1; k <= wide; k++)
                    dp[i][k] = min( dp[i-1][k] + price, dp[i][k] );

                for(l = wide + 1; l <= MAX; l++)
                    dp[i][wide] = min( dp[i-1][l] + price, dp[i][wide]);
            }

        }
        printf("%d---",dp[n][100]);
        double Max = 0.0;

        for (i = 1; i <= Max ; i++)
            if (1.0 * i / dp[n][i] > Max)
                Max = 1.0 * i / dp[n][i];

        printf("%.3lf\n", Max);

    }
}
