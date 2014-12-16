#include<stdio.h>
#include<string.h>
#define MAX 205
int dp[MAX][MAX];
char str1[MAX],str2[MAX];
int main()
{
    int max;
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=strlen(str1);i++)dp[i][0]=0;
        for(int j=0;j<=strlen(str2);j++)dp[0][j]=0;

        for(int i=1;i<=strlen(str1);i++)
            for(int j=1;j<=strlen(str2);j++)
            {
                if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=(dp[i-1][j]>dp[i][j-1])?(dp[i-1][j]):(dp[i][j-1]);
            }
        printf("%d\n",dp[strlen(str1)][strlen(str2)]);
    }
    return 0;
}
