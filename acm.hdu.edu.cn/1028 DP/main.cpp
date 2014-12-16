#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 121
int dp[maxn][maxn]= {0};
int main()
{
    int i,j;
    for(i=1; i<=121; i++)
        dp[1][i]=dp[i][1]=1;
    for(i=2; i<121; i++)
    {
        for(j=2; j<=121; j++)
        {
            if(i<j)
                dp[i][j]=dp[i][i];
            else if(i==j)
                dp[i][j]=1+dp[i][j-1];
            else if(i>j)
                dp[i][j]=dp[i-j][j]+dp[i][j-1];
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",dp[n][n]);
    return 0;
}
