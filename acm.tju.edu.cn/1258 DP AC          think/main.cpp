#include <cstdio>
#include <cstring>
#include <cmath>
const int Max = 1001;
int dp[102][Max];
int min(int x, int y)
{
    if (x > y)
    return y;
    else
    return x;
}
int main()
{
	int N, n, m;
	int i, j, k;
	int wide, price;
	scanf("%d", &N);
	while(N--)
	{

		scanf("%d", &n);
		memset(dp, 0x7f, sizeof(dp));

		for(i = 1; i <= Max; ++i)
			dp[0][i] = 0;

		for(i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			for(j = 0; j < m; ++j)
			{
				scanf("%d %d", &wide, &price);

                for(k = 1; k <= wide; k++)
                    dp[i][k] = min( dp[i-1][k] + price, dp[i][k] );

                for(k = wide + 1; k <= 2 * wide; k++)
                    dp[i][wide] = min( dp[i-1][k] + price, dp[i][wide]);
			}
		}


		double ret = 0.0;

		for(i = 1; i <= 2 * wide; ++i)
			if((1.0*i/dp[n][i]) > ret)
				ret = 1.0*i/dp[n][i];

		printf("%.3lf\n", ret);
	}
	return 0;
}

