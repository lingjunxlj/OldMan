#include <cstdio>
#include <cmath>
#include <string>
int dist[151][151];
int max(int x,int y)
{
    if (x>y)
    return x;
    return y;
}
struct A
{
    int x;
    int y;
    int h;
}a[151];
int main()
{
    int n,x=0;
    while (scanf("%d",&n),n)
    {
        x++;
        memset(dist,0,sizeof(dist));
        int i,j,k=1;
        for (i=0;i<n;i++)
        {
            scanf("%d %d %d",&a[k].x,&a[k].y,&a[k].h);
            a[k+1].x=a[k].h;
            a[k+1].y=a[k].y;
            a[k+1].h=a[k].x;
            a[k+2].x=a[k].x;
            a[k+2].y=a[k].h;
            a[k+2].h=a[k].y;
            k+=3;
        }
        int maxm=0;
        n=k;
        for (i=1;i<n;i++)
        for (j=1;j<n;j++)
        {
            if ((a[j].x>a[i].x &&a[j].y>a[i].y)||(a[j].x>a[i].y &&a[j].y>a[i].x))
            dist[j][i]=a[i].h+a[j].h;
            else dist[j][i]=-1;
        }
        for(i=0;i<n;i++)
        dist[i][i]=0;
        for (k=1;k<n;k++)
        for (i=1;i<n;i++)
        {
            if (dist[i][k]==-1)
            continue;
            for (j=1;j<n;j++)
            {
                if (dist[i][j]==-1 || dist[k][j]==-1)
                continue;
                dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]-a[k].h);
                maxm=max(maxm,dist[i][j]);
            }
        }
        printf("Case %d: maximum height = %d\n",x,maxm);
    }
}
