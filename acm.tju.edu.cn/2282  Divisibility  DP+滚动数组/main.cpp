#include <cstdio>
#include <string>
int dp[2][101];
int main()
{
    int num;
    int n,i,j,k;
    while (scanf("%d %d",&n,&k)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&num);
        dp[0][(num%k+k)%k]=1;
        for (i=1;i<n;i++)
        {
            scanf("%d",&num);
            memset(dp[1],0,sizeof(dp[1]));
            for (j=0;j<k;j++)
            {
                if (dp[0][((j-num+k)%k+k)%k])
                dp[1][j]=1;
                if (dp[0][((j+num+k)%k+k)%k])
                dp[1][j]=1;
            }
            memcpy(dp[0],dp[1],sizeof(dp[0]));
        }
        if (dp[0][0])
        printf("Divisible\n");
        else
        printf("Not divisible\n");
    }
}
