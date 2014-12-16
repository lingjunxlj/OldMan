#include <iostream>
#include <cmath>
using namespace std;
#define MAX 201
#define INF 10000.0f
float matrix[MAX][MAX];
int s[MAX];
float dis[MAX];
typedef struct point
{
    int x;
    int y;
    int flag;
}point;
void Dijkstra(int &n)
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=matrix[1][i];
        s[i]=0;
    }
    s[1]=1;
    int u;
    for(int i=1;i<=n-1;++i)
    {
        float minDis=INF;
        for(int j=1;j<=n;++j)
        if(!s[j]&&dis[j]<minDis)
        {
            minDis=dis[j];
            u=j;
        }
        s[u]=1;
        for(int j=1;j<=n;++j)
        if(!s[j]&& matrix[u][j]!= INF)
        dis[j]=min(dis[j],max(dis[u],matrix[u][j]));
    }
}
int main()
{
    int n;
    point p[MAX];
    int count=0;
    while(scanf("%d",&n)&&n!= 0)
    {
        for(int i=2;i<=n-1;++i)
        p[i].flag = 0;
        scanf("%d%d",&p[1].x,&p[1].y);
        p[1].flag=1;
        scanf("%d%d",&p[n].x,&p[n].y);
        p[n].flag=1;
        for(int i=2;i<=n-1;++i)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].flag=1;
        }
        for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
        if(i!=j&&p[i].flag)
        matrix[j][i]=matrix[i][j]=sqrt(((float)(p[i].x-p[j].x)*(p[i].x-p[j].x))+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        else
        matrix[i][j]=INF;
        Dijkstra(n);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++count, dis[n]);
    }
    return 0;
}
