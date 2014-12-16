#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=305;
int n,m;
int map[MAX][MAX];
int xm[MAX],ym[MAX];
bool check[MAX];
bool SearchPath(int u)
{
    int i;
    for (i=1;i<=m;i++)
    {
        if (map[u][i]==1&&!check[i])
        {
            check[i]=1;
            if (ym[i]==-1||SearchPath(ym[i])==1)
            {
                ym[i]=u;
                xm[u]=i;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int i;
    int ret=0;
    memset(xm,-1,sizeof(xm));
    memset(ym,-1,sizeof(ym));
    for (i=1;i<=n;i++)
    {
        if (xm[i]==-1)
        {
            memset(check,0,sizeof(check));
            if (SearchPath(i))
            ret++;
        }
    }
    return ret;
}
int main()
{
    int x;
    scanf("%d",&x);
    while (x--)
    {
        memset(map,-1,sizeof(map));
        scanf("%d %d",&m,&n);
        int i;
        for(int i=1;i<=m;i++)
        {
            int t;
            scanf("%d",&t);
            while(t--)
            {
                int s;
                scanf("%d",&s);
                map[s][i]=1;
            }
        }
        int sum=MaxMatch();
        if (sum==m)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
