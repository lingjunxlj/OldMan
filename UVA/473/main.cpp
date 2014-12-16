#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, t, m;
int Time[1001], dp[1001][101][101];

int max(int a, int b)
{
    return a > b? a:b;
}
int max(int a, int b, int c)
{
    return max(a, max(b, c));
}
int d(int i, int j, int k)
{
    if (i > n)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (j < Time[i])
    {
        if (k > 0)
           return dp[i][j][k] = max(1 + d(i + 1, t - Time[i], k - 1), d(i + 1, j, k));
        else
           return dp[i][j][k] = d(i + 1, j, k);
    }
    else
    {
        if(k > 0)
            return dp[i][j][k] = max(1 + d(i+1, j - Time[i], k), max(d(i + 1, t - Time[i], k - 1), d(i + 1, j, k)));
        else
            return dp[i][j][k] = max(1 + d(1 + i, j - Time[i], k), d(i + 1, j, k));
    }
}
int main()
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        char temp;
        scanf("%d %d %d", &n, &t, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%c", &Time[i], &temp);
            //cin>>temp;
            //Time[i] = temp[0] - '0';
            //cout<<Time[i];
        }


        for (int i = 0;i <= n; i++)
            for (int j = 0;j <= t; j++)
                for (int k = 0;k <= m; k++)
                    dp[i][j][k] = -1;

        printf("%d\n",d(1,0,m));
        if (Case > 0)
            printf("\n");

    }

}
