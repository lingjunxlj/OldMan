#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX=99999;
const int MAXM=200;
bool flag[MAXM];
double map[200][200];
double dist[200];
int n;
struct node
{
    double a;
    double b;
}mapp[200];

double DIST(int i,int j)
{
    double temp;
    temp=sqrt((mapp[i].a-mapp[j].a)*(mapp[i].a-mapp[j].a)+(mapp[i].b-mapp[j].b)*(mapp[i].b-mapp[j].b));
    return temp;
}
double Prim()
{
    double sum=0;
    double i,j,min,mark;
    for (i=1;i<=n;i++)
    {
        dist[i]=map[1][i];
    }
    flag[1]=true;
    for (i=1;i<=n-1;j++)
    {
        min=MAX;
        for (j=1;j<=n;j++)
        {
            if (!flag[j]&&dist[j]<min)
            {
                min=dist[j];
                mark=j;
            }
            sum+=min;
            flag[mark]=true;
            for (j=1;j<=n;j++)
            {
                if (!flag[j]&&map[mark][j]<dist[j])
                dist[j]=map[mark][j];
            }
        }
    }
    return sum;
}
int main()
{
    scanf ("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
    scanf ("%lf%lf",&mapp[i].a,&mapp[i].b);
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    map[i][j]=DIST(i,j);
    memset(flag,false,sizeof(flag));
    memset(dist,MAX,sizeof(dist));
    memset(map,MAX,sizeof(map));
    printf ("%d\n",Prim());
}
    
