#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=601;
const int INF=0x7ffff;
int map[MAX][MAX],dist[MAX],camp[MAX],n,i,j,u;
bool flag[MAX],flag2[MAX];
void Dijkstra()
{
    int min;
    for(i=1;i<=n;++i)
    {
        dist[i]=map[1][i];
    }
    dist[1] = 0;
    bool flag1=0;
    for ( i = 1; i <= n; i++ )
    {
        min = INF;
        for ( j = 0; j < n; j++ )
        if ( !flag[j] && dist[j] < min )
        {
                min = dist[j];
                u = j;

        }
        if ( u == n ) break;
        flag[u] = 1;
        for (j = 1; j <= n; j++ )
        {

            if ((camp[u]==camp[j])&&!flag[j] && dist[j] > dist[u] + map[u][j])
            dist[j] = dist[u] + map[u][j];
            if ((camp[u]!=camp[j])&&!flag[j] && dist[j] > dist[u] + map[u][j])
            {
                if (!flag1)
                {
                    dist[j] = dist[u] + map[u][j];
                    flag1=1;
                }
            }
        }
    }
}
int main()
{
    while (scanf("%d",&n),n)
    {
        memset(flag, 0, sizeof (flag) );
        memset(dist, INF, sizeof (dist));
        memset(map, INF, sizeof (map));
        int m;
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
        }
        for (i=1;i<=n;i++)
        {
            scanf("%d",&camp[i]);
        }
        Dijkstra();
        printf("%d\n",dist[2]);
    }
}
