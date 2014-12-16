#include<math.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<float.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10000001
int go[41];
int dp[MAX][41];
int main()
{
    int n,w,k,i,j,p;
    while(scanf("%d%d",&n,&w)!=EOF)
    {
        for(i=0;i<=w;i++)
        memset(dp[i],0,sizeof(dp[i]));
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d",&go[i]);
        }
        for(i=0;i<k;i++)
        {
            for(p=w;p>=go[i];p--)
            {
               for(j=n;j>=1;j--)
               {
                    dp[p][j]=max(dp[p][j],dp[p-go[i]][j-1]+go[i]);
                }
            }
        }
        printf("%d\n",dp[w][n]);
    }
    return 0;
}
