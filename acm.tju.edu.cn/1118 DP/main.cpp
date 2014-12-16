#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 101;
double dp[1001][N];
int main()
{
    int n, m, c, temp, i, j;
    while(scanf("%d",&c))
    {

        if(c==0)
        break;
        scanf("%d %d", &n, &m);
        if(m > c || m > n)
        {
            printf("0.000\n");
            continue;
        }
        if(n>1000)
        n = 1000 + n%2;
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        dp[0][0] = 1;
        temp=min(n,c);
        for(i = 2; i <= n; i++)
        {
          memset(dp[i], 0, sizeof(dp[i]));
          for(j = 0; j <= temp; j++)
          {
              if(j == 0)
              dp[i][j] = dp[i-1][1]/c;

              else if(j == c)
              dp[i][j] = dp[i-1][j-1]/c;

              else
              dp[i][j] = ( dp[i-1][j-1] * (c-j+1) ) / c +  ( dp[i-1][j+1] * (1+j) ) / c;
          }
        }
        printf("%.3lf\n", dp[n][m]);
    }
}
