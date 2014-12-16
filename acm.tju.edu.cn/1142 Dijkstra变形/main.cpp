#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double inf=10000.0f;
double map[201][201],dist[201];
bool Flag[201];
struct node
{
    int x;
    int y;
    int flag;
}coordinate[201];
void Dijkstra(int n)
{
   int i,j;
   for (i=1;i<=n;i++)
   dist[i]=map[1][i];
   Flag[1]=1;
   int u;
   double minm=inf;
   for (i=1;i<=n-1;i++)
   {
       minm=inf;
       for (j=1;j<=n;j++)
       {
           if (!Flag[i]&&dist[i]<minm)
           {
               minm=dist[i];
               u=j;
           }
       }
       Flag[u]=1;
       for (j=1;i<=n;j++)
       {
           if (!Flag[j]&&map[u][j]!=inf)
           dist[j]=min(dist[j],max(dist[u],map[u][j]));
       }
   }
}
int main()
{
    int q=0;
    {
        int n;
        int i,j;
        while (scanf("%d",&n)&&n!=0)
        {
            q++;
            for(i=1;i<=n;i++)
            coordinate[i].flag=0;
            memset(Flag,0,sizeof(Flag));
            scanf("%d %d",&coordinate[1].x,&coordinate[1].y);
            scanf("%d %d",&coordinate[n].x,&coordinate[n].y);
            coordinate[1].flag=1;
            coordinate[n].flag=1;
            for (i=2;i<=n-1;i++)
            {
                scanf("%d %d",&coordinate[i].x,&coordinate[i].y);
                coordinate[i].flag=1;
            }
            for (i=1;i<=n;i++)
            for (j=1;j<=i;j++)
            {
                if (coordinate[i].flag&&i!=j)
                {
                    map[i][j]=sqrt((double)(coordinate[i].x-coordinate[j].x)*(coordinate[i].x-coordinate[j].x)+(double)(coordinate[i].y-coordinate[j].y)*(coordinate[i].y-coordinate[j].y));
                }
                else
                map[i][j]=inf;
            }
            Dijkstra(n);
            printf("Scenario #%d\nFrog Distance = %.3lf\n\n",q,dist[n]);
        }
    }
}




