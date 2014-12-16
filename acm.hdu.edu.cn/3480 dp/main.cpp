#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10010
#define maxm 5010
#define inf 1<<30
int val[maxn];
int dp[maxm][maxn];
int s[maxm][maxn];
int n,m;
int fun(int x)
{
    return x * x;
}
int main()
{
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i ++)
            scanf("%d",&val[i]);
        sort(val + 1,val + 1 + n);
        for(int i = 1; i <= n; i ++)
        {
            dp[1][i] = fun(val[i] - val[1]);
            s[1][i] = 0;
            dp[i][i] = 0;
        }
        for(int i = 2; i <= m; i ++)
        {
            s[i][n + 1] = n - 1;
            for(int j = n; j > i ; j --)
            {
                dp[i][j] = -1;
                for(int k = s[i - 1][j] ; k <= s[i][j + 1] && k < j ; k ++)
                {
                    int tmp = dp[i - 1][k] + fun(val[j] - val[k + 1]);
                    if(dp[i][j]==-1||dp[i][j] > tmp)
                    {
                        dp[i][j] = tmp;
                        s[i][j] = k;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cas++,dp[m][n]);
    }
    return 0;
}
