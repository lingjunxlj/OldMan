#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAX=201;
const int inf=0x7f;
int map[MAX][MAX],Max[MAX],Min[MAX];
int main()
{
    int i,j,k,a,b,n;
    while (scanf("%d",&n),n)
    {

        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i!=j)
        map[i][j]=inf;
        memset(Max,0,sizeof(Max));
        for (i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            for (j=1;j<=m;j++)
            {
                scanf("%d %d",&a,&b);
                map[i][a]=b;
            }
        }
        for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
        int max1=-1,min1=0x7f,res;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if (Max[i]<map[i][j])
            {
                Max[i]=map[i][j];
            }
        }
        for(int i = 1; i <= n; i++)
        if (max1<Max[i])
        max1=Max[i];
        for(int i = 1; i <= n; i++)
        {
            if (Max[i]<min1)
            {
                min1=Max[i];
                res=i;
            }
        }
        if (min1==0x7f)
        printf("disjoint\n");
        else
        printf("%d %d\n",res,min1);
    }
}


