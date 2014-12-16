#include <iostream>
using namespace std;
const int MAX=1001;
const int inf=0x7f;
int map[MAX][MAX],lowcast[MAX],x1[MAX],y1[MAX],EY[MAX];
bool flag[MAX];    
int main()
{
    int n,m,i,j,temp1,temp2;
    int x2,y2;
    cin>>n;
    memset(flag,true,sizeof (flag));
    memset(map,inf,sizeof (map));
    for (i=1;i<=n;i++)
    {
        cin>>x1[i]>>y1[i];
    }
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
        temp1=x1[i]-x1[j];
        temp2=y1[i]-y1[j];
        map[i][j]=map[j][i]=temp1*temp1+temp2*temp2;
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>x2>>y2;
        map[x2][y2]=map[y2][x2]=0;
    }
    int min,sum,u;
    for (i=1;i<=n;i++)
    {
        lowcast[i]=map[1][i];
        EY[i]=1;
    }
    for (i=1;i<=n;i++)
    {
        min=inf;
        for(j=1;j<=n;j++)
        {
            if (flag[j]&&min>lowcast[j])
            {
                min=lowcast[j];
                u=j;
            }
        }
        flag[u]=false;
        if (min>0)
			printf("%d %d\n",(u<EY[u]?u:EY[u]),(u>EY[u]?u:EY[u]));
        for (j=1;j<=n;j++)
        {
            if (flag[j]&&lowcast[j]>map[u][j])
            {
                lowcast[j]=map[u][j];
                EY[j]=u;
            }
        }
    }
    while (1);
}
      
