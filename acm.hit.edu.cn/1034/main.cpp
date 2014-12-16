#include <cstdio>
#include <string>
int dp[60001];
int mar[7];
int main()
{
    int c=0;
    while(++c)
    {
        int i,j,k;
        int sum=0;
        for(i=1;i<=6;++i)
        {
            scanf("%d",&mar[i]);
            sum+=mar[i]*i;
        }
        if(sum==0)
        break;
        if(sum%2)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",c);
            continue;
        }
        sum/=2;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int pos;
        for(i=1;i<=6;++i)
        {
            for(j=sum;j>=0;--j)
            {
                if(dp[j]==0)
                continue;
                if(dp[j+i]==1)
                continue;
                pos=j;
                for(k=0;k< mar[i];++k)
                {
                    pos+=i;
                    if(pos>sum)
                    break;
                    dp[pos]=1;
                }
            }
        }
        printf("Collection #%d:\n",c);
        if(dp[sum]==1)
        printf("Can be divided.\n");
        else
        printf("Can't be divided.\n");
        printf("\n");
    }
}
