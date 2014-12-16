#include <cstdio>
#include <string>
const int MAX=110;
int map[MAX][MAX],deger[MAX],lower[MAX],CutPoint[MAX],sum,n,max;
bool flag[MAX];
void DFS(int u)
{
    int i;
    deger[u]=lower[u]=sum++;
    for (i=1;i<=n;i++)
    if (map[u][i])
    {
        if (!flag[i])
        {
            flag[i]=true;
            DFS(i);
            if (lower[u]>lower[i])
            lower[u]=lower[i];
            if ((deger[u]==1&&deger[i]!=2)||(deger[u]!=1&&lower[i]>=deger[u]))
            CutPoint[u]=1;
        }
        else
        {
            if (lower[u]>deger[i])
            lower[u]=deger[i];
        }
    }
}
int main()
{
    int i,j,x,y;
    char temp;
    while (scanf("%d",&n),n)
    {
        memset(flag,false,sizeof(flag));
        memset(map,0,sizeof(map));
        memset(deger,0,sizeof(deger));
        memset(lower,0,sizeof(lower));
        memset(CutPoint,0,sizeof(CutPoint));
        scanf("%d",&x);
        while (x)
        {
            scanf("%d%c",&y,&temp);
            map[x][y]=map[y][x]=1;
            if (temp=='\n')
            scanf("%d",&x);
        }
        flag[1]=true;
        sum=1;
        DFS(1);
        max=0;
        for (i=1;i<=n;i++)
        if(CutPoint[i])
        max++;
        printf("%d\n",max);
    }
}
