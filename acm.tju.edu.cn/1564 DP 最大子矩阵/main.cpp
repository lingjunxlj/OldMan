#include <cstdio>
#include <string>
int map[150][150][150];
int num[150][150];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        int i,j,k;
        for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            scanf("%d",&num[i][j]);
            map[i][i][j]=num[i][j];
        }
        for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
        for (k=1;k<=n;k++)
        {
            map[i][j][k]+=map[i][j-1][k]+num[j][k];
        }
        int sum,ans=INT_MIN;
        for (i=1;i<=n;i++)
        for (j=i;j<=n;j++)
        {
            sum=0;
            for (k=1;k<=n;k++)
            {
                if (sum>=0)
                sum+=map[i][j][k];
                else
                sum=map[i][j][k];
                if (ans<sum)
                ans=sum;
            }
        }
        printf("%d\n",ans);
    }
}
