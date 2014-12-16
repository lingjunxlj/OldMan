#include <iostream>
#include <cstdio>
using namespace std;
int dp[5001][1001],data[5005];
int squ(int t)
{
    return t*t;
}
int min(int a, int b)
{
    return a > b?b:a;
}
int main()
{
    int i, j, cas, k, n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d %d", &k, &n);
        for(i = n; i >= 1; i--)
            scanf("%d", &data[i]);
        k += 8;
        for(j = 1; j <= k; j++)
        {
            i = j * 3;
            dp[i][j] = dp[i - 2][j - 1] + squ(data[i] - data[i-1]);
            for(i++;i <= n; i++)
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1]+squ(data[i]-data[i-1]));
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
