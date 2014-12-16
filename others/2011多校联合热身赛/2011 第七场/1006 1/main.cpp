#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, r;
int dp[501][51][51];
int a[501];
int i, j, k;
int main()
{

     while(~scanf("%d %d %d",&n,&m,&r))
     {
         for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        if(n%(r+1)+n/(r+1)*r>=m)                        //此处是判断能否有足够的休息时间
        {
            int ans=-1;
            memset(dp,-1,sizeof(dp));                  //初始化所有时间段为-1
            dp[0][0][0]=0;
            for(i=0;i<n;++i)                           //确定第i分钟
            {
                for(j=0;j<=n-m;++j)                      //指第i分钟之前包括第i分钟具有的睡眠时间
                {
                    for(k=0;k<r;++k)                   //指从第i分钟向前连续睡k分钟，大牛采用的是由前往后推的方式
                    {
                         if(dp[i][j][k]==-1)
                            continue;  //当前者为-1时说明该点不具有值
                         if(j < n-m)
                             dp[i+1][j+1][k+1] = dp[i][j][k] + a[i+1];//这是连续时间的效应
                         if(dp[i+1][j][0]<dp[i][j][k])
                             dp[i+1][j][0]=dp[i][j][k]; //这个0十分重要，因为当你手算推导时会发现，最终会回到某一分钟的0这个点，它代表前面具有j个睡眠时间时的最大值
                     }
                     if(dp[i+1][j][0]<dp[i][j][k])
                         dp[i+1][j][0]=dp[i][j][k];//不要忘记0要统计i下j分钟下的最大值
                 }
             }
             for(i=0;i<=r;++i)
             {
                 if(ans<dp[n][n-m][i])
                     ans=dp[n][n-m][i];
             }                                   //最后只要求解在n分钟下有m分钟睡眠时间时的最大值
             printf("%d\n",ans);
         }
         else
             printf("impossible\n");
     }
     return 0;
 }
