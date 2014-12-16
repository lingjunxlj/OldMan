#include<iostream>
#include<cstdio>
using namespace std;
int a[101];
long long dp[101][101];

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int i,j,p;
        if(n == 0 && k == 0)
            break;
        memset(dp,0,sizeof(dp));
        for(i = 1 ;i <= n;i++)
        {
            scanf("%d",&a[i]);
            dp[i][1] = 1;
        }
        for(j = 2; j <= k;j++)
            for(i = j;i <= n;i++)
                for(p = j-1;p < i;p++)
                {
                    if(a[i] > a[p])
                        dp[i][j] += dp[p][j-1];
                }
        long long sum = 0;
        for(i =k;i <= n;i++ )
            sum += dp[i][k];
        printf("%lld\n",sum);
    }
    return 0;
}
