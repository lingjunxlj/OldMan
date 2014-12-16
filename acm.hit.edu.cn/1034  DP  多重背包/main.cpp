#include <iostream>
#include <cstdio>
using namespace std;
int a[7],sum;
char dp[60002];
int main()
{
    int x=0;
    while (scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]))
    {
        x++;
        sum=0;
        int i,j;
        for (i=1;i<=6;i++)
        sum+=a[i]*i;
        if (sum==0)
        break;
        printf("Collection #%d:\n",x);
        if (sum%2)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        sum>>=1;
        dp[0]=1;
        int pos;
        for (i=1;i<=6;i++)
        for (j=sum;j>=0;j--)
        {
            if (dp[j]==0)
            continue;
            if (dp[i+j]==1)
            continue;
            pos=j;
            int k;
            for (k=0;k<a[i];k++)
            {
                pos+=i;
                if (pos>sum)
                break;
                dp[pos]=1;
            }
        }
        if (dp[sum]==1)
        printf("Can be divided.\n\n");
        else
        printf("Can't be divided.\n\n");
    }
}
