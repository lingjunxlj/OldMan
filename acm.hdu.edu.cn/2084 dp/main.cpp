#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int num[101][101];
int dp[101][101];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i = 1 ; i <= n; i++)
            for (int j = 1; j <= i; j++)
                cin>>num[i][j];

        memset(dp, 0, sizeof(dp));
        dp[1][1] = num[1][1];
        dp[2][1] = dp[1][1] + num[2][1];
        dp[2][2] = dp[1][1] + num[2][2];
        for (int i = 3; i <= n; i++)
            for (int j = 1; j <= i; j++)
            {
                if (j == 1)
                    dp[i][j] = dp[i - 1][j] + num[i][j];
                else if (j == i)
                    dp[i][j] = dp[i - 1][j - 1] + num[i][j];
                else
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + num[i][j];

            }
        int Max = 0;
        for (int i = 1; i <= n; i++)
            if (Max < dp[n][i])
                Max = dp[n][i];
        printf("%d\n", Max);
    }
}
