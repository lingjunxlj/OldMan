#include <cstdio>
using namespace std;
double dp[1510][1510];

int main()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1;i <= 1500;i++)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) / 2;
        for (int j = 1;j <= i; j++)
            dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) / 2;
    }
    int T;
    scanf("%d",&T);
    for (int z = 1;z <= T;z++)
    {
        int n;
        scanf("%d",&n);
        double ans = 0;
        for (int i = 0;i <= n;i++)
            ans = ans + dp[n][i] * i;
        ans = ans * 2;
        printf("Case %d: %.6lf\n",z,ans);
    }
    return 0;
}
