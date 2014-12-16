#include <iostream>
using namespace std;
#define INF 1<<30
#define MAX 300
bool flag[MAX];
int map[MAX][MAX];
struct pan
{
    int dist;
    int p;
}px[MAX],temp;
int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        int v,u,w,K;
        if (n==0)
        break;
        int i,j,min;
        memset(flag,false,sizeof (flag));       
        memset(map,9999,sizeof (map));
        for (i=0;i<300;i++)
        {
            px[i].dist=9999;
            px[i].p=i;
        }
        px[0].dist=0;
        for (i=0;i<m;i++)
        {
            cin>>v>>u>>w;
            map[v][u]=map[u][v]=w;
        }
        cin>>K;
        
        for (i=1;i<=n;i++)
        {
            min=INF;
            for (j=0;j<n;j++)
            {
                if (!flag[j]&&px[j].dist<min)
                {
                    min=px[j].dist;
                    u=j;
                }
            }
            if (u==n)
            break;
            flag[u]=true;
            for (j=0;j<n;j++)
            {
                if (!flag[j]&&px[j].dist>px[u].dist+map[u][j])
                px[j].dist=px[u].dist+map[u][j];
            }
        }
        
        for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
        {
            if (px[j].dist>px[j+1].dist)
            {
                temp=px[j];
                px[j]=px[j+1];
                px[j+1]=temp;
            }
        }
        cout<<px[K].p<<endl;
    }
}
        
        
        
        
        
